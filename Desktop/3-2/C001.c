#include <stdio.h>

int main(){
    int size, stars, blank1, blank2;

    scanf("%d",&size);

    for(int i=0; i<size; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        printf("*");
        blank1 = 2*(size - i -1);
        for(int j=0; j<blank1; j++){
            printf(" ");
        }
        printf("*\n");
    }  /// 첫번째 트로피 모양 

    for(int i=0; i<size; i++){
        for(int j=0; j<2*size; j++){
            printf("*");
        }
        printf("\n");
    } // 중간 n개 원통형 

    for(int i=0; i<size; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        for(int j=0; j<2*(size-i); j++){
            printf("*");
        }
        for(int j=0; j<i; j++){
            printf(" ");
        }
        printf("\n");
    } // 밑으로 갈수록 작아지는 피라미드 

    for(int i=0; i<2*size; i++){
        printf("*");
    }
    

    return 0; 
}