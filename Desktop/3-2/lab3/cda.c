#include <stdio.h>

int main(){
    char a [3][50];

    a[3][50] = "hello world";

    print("%s", &a);

    return 0; 
}