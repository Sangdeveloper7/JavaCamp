    int size, stars, blank1, blank2;

    scanf("%d",&size);
    for(int i=0; i<size; i++){
        printf("*");
        stars = 8-2*i;
        for(int j=0; j<stars; j++){
            printf(" ");
        }
        printf("*\n");
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<2*size; j++){
            printf("*");
        }
        printf("\n");
    }