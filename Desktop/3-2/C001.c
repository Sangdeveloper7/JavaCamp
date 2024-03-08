#include <stdio.h>

int main(){
    int size, stars, blank1, blank2 = 0;

    scanf("%d",&size);
    stars = 2*size;
    for(int i =0; i< size; i++){
        printf("**");
    }

    return 0;
}