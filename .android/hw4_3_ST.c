#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#include "Console.h"

#define TRUE 1
#define FALSE 0

#define ESC 27

#define	MULTITHREAD
#ifdef	MULTITHREAD

#define MAX_THREAD 16

typedef struct {
	int idx;
	int no_thread;

	int width;
	int cy;
	int bar_len;
	int delay;
} ThreadParam;

void* ThreadFn(void *vparam);

int cont = TRUE;		 // use this variable to terminate threads

#endif	//	MULTITHREAD

int DrawBar(int sx, int sy, int len, char c);

int main(int argc, char *argv[])
{
#ifdef	MULTITHREAD
	if(argc < 2){
		printf("Usage: %s <no_thread>\n", argv[0]);
		return 0;
	}
	int no_thread = atoi(argv[1]);
#endif	//	MULTITHREAD

	pthread_t threads[MAX_THREAD];
    ThreadParam params[MAX_THREAD];

	int screen_width = getWindowWidth();
	int screen_height = getWindowHeight() - 3;

	clrscr();
	gotoxy(1, 1);
	printf("screen size = %d x %d\n", screen_width, screen_height);

	gotoxy(1, screen_height);
	printf("Press ESC to quit.\n");

	EnableCursor(FALSE);

//	Convert the following code to animate bouncing bars using multiple threads

	int bar_len = 7;
	int x = (screen_width - bar_len) / 2;
	int dx = 1;
	int cy = screen_height / 2;


	for (int i = 0; i < no_thread; i++) {
        // ThreadParam 구조체 초기화
        params[i].idx = i;
        params[i].no_thread = no_thread;
        params[i].width = screen_width;
        params[i].cy = i * (screen_height / no_thread); // y 좌표는 스레드 인덱스에 비례하여 배정
        params[i].bar_len = bar_len;
		params[i].delay = 3000 + (i * 2000); 
        // pthread_create()를 사용하여 스레드를 생성합니다.
        if (pthread_create(&threads[i], NULL, ThreadFn, (void*)&params[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

	

	while(1){
		int prevx = x;

		if(x + dx < 1 || x + dx + bar_len - 1 > screen_width)
			dx = -dx;
		x += dx;

		if(dx > 0)
			gotoxy(prevx, cy);
		else
			gotoxy(prevx + bar_len - 1, cy);
		putchar(' ');
		DrawBar(x, cy, bar_len, '=');
		
		gotoxy(1, screen_height);
		fflush(stdout);

		usleep(10000);

		if(kbhit() && getch() == ESC)	// breaks if the user presses ESC
			break;
	}


	EnableCursor(TRUE);
	gotoxy(1, screen_height);
	printf("Bye!                             \n");

	return 0;
}


int DrawBar(int sx, int sy, int len, char c)
{
	gotoxy(sx, sy);
	for(int i = 0; i < len; i++)
		putchar(c);
	return 0;
}

#ifdef	MULTITHREAD
void* ThreadFn(void *vparam)
{
	ThreadParam *param = (ThreadParam*)vparam;
    int x = (param->width - param->bar_len) / 2;  // 시작 x 위치
    int dx = 1;  // x 이동 방향
    int cy = param->cy;  // y 위치는 고정

    while (cont) {
        int prevx = x;

        // 화면 끝에 도달하면 방향 전환
        if (x + dx < 1 || x + dx + param->bar_len - 1 > param->width)
            dx = -dx;
        x += dx;

        LockDisplay();  // 화면 출력 전에 잠금
        if (dx > 0)
            gotoxy(prevx, cy);
        else
            gotoxy(prevx + param->bar_len - 1, cy);
        putchar(' ');
        DrawBar(x, cy, param->bar_len, '=');
        UnlockDisplay();  // 화면 출력 후 잠금 해제

        fflush(stdout);
        usleep(param->delay);  // 스레드별 지연시간
    }
    return NULL;

}
#endif	//	MULTITHREAD

