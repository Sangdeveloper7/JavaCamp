#include <stdio.h>


int main(){
    int person[4][3];
    int sum[3] = {0, 0, 0};
    float ratio[3];
    int i, j;
    printf("Check room (Men) \n");
    for(i = 0; i< 2; i++){
        for(int j=0; j<3; j++){
            printf("Room #%d0%d >  ", i+1, j+1);
            scanf("%d", &person[i][j]);
        }
    } // 남자방 인원수 입력 

    printf("Check room (Women) \n");
    for(i = 2; i< 4; i++){
        for(int j=0; j<3; j++){
            printf("Room #%d0%d >  ", i+1, j+1);
            scanf("%d", &person[i][j]);
        }
    } // 여자방 인원수 입력 

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            sum[0] += person[i][j];
        }
    } // 남자방 인원수 합

    

    for(int i=2; i<4; i++){
        for(int j=0; j<3; j++){
            sum[1] += person[i][j];
        }
    } // 여자방 인원수 합 

    sum[2] = sum[0] + sum[1];
    ratio[0] = sum[0] / 24.0;
    ratio[1] = sum[1] / 24.0;
    ratio[2] = sum[2] / 48.0;


    printf("Check Result\n");
    printf("Men: %d/24 (%.1f%%)\n", sum[0], ratio[0]*100);
    printf("Women: %d/24 (%.1f%%)\n", sum[1], ratio[1]*100);    
    printf("Total: %d/48 (%.1f%%)\n", sum[2], ratio[2]*100);


    return 0;
}