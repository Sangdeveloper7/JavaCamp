#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Student;
void createScore(struct Student *s_n){
    int l, m, e;
        printf("성적을 입력해 주세요 국 수 영 순으로");
        scanf("%d %d %d", &s_n->laug, &s_n->math, &s_n->eng);
    }

    void readScore(struct Student s_n){

        printf("%s 의 점수는 국어: %d 수학: %d 영어 %d 입니다.", s_n.name, s_n.laug, s_n.math, s_n.eng);
    }

int updateScore(struct Student *s){
    printf("수정할 성적을 국 영 수 순서대로 입력하세요.");
    int l, m ,e;
    scanf("%d %d %d", &l, &m, &e);
    if(l > 100 || m > 100 || e > 100 || l <0 || m < 0 || e < 0){
        return 0;
    }else{
        s->laug = l;
        s->math = m;
        s->eng = e;
        return 1;
    }
}

int deleteScore(struct Student *s){
    printf("만약에 정말 삭제하고 싶으시면 1번 아니면 0 번을 눌러주세요. ");
    int k;
    scanf("%d", &k);
    if(k == 1){
        s->laug = -1;
        s->math = -1;
        s->eng = -1;
    }
    else{
        return 0;
    } 
    return 0; 
}
int main(){
    Student st;
    st->name = "Student";
    int c;
    // st1.sn = 101;
    // st1.name = "Student;
    // createScore(&st1);
    // readScore(st1);
    while(1){
        printf("메뉴를 선택하세요. \n  1. 사용자 추가 \n 2. 사용자의 성적 입력받기 \n 3. 사용자의 성적 수정하기 \n 4. 사용자의 성적 삭제하기 \n 5. 나가기");
        scnaf("%d", &c);
        switch(c){
        case 1: createScore(&st);
            break;
        case 2: readScore(st);
        break;
        case 3: updateScore(&st);
        break;
        case 4: deleteScore(&st);
        break;
        case 5: exit(0);
        }
    }
   




    return 0; 
}

typedef struct Student{
        int sn;
        char name[20];
        int laug,math, eng;
    } Student;


 