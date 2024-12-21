#include<stdio.h>
#define MAX 50

int mai(){
    int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
    int arows, acolumns, brows, bcolumns;
    int i, j, k;
    int sum = 0;


    printf("Enter the number of rows and columns of the matrix a : ");
    scanf("%d %d", &arows, &acolumns);
    for(i = 0; i < arows; i++){
        for(j = 0; j < acolumns; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the matrix b : ");
    scanf("%d %d", &brows, &bcolumns);

    for(i = 0; i < brows; i++){
        for(j = 0; j < bcolumns; j++){
            scanf("%d", &b[i][j]);
        }
    }

    if(brows != acolumns){
        printf("Sorry! we cannot multiply the matrices a and b.. Please try again.");
    }

    else{
        for(i = 0; i < arows; i++){
            for(j = 0; j < bcolumns; j++){
                for(k = 0; k < brows; k++){
                    sum += a[i][k] * b[k][j];
                }
                product[i][j] = sum;
                sum = 0;
            }
        }

        // print the array element
        printf("Resultant matrix : ");
        for(i = 0; i < arows; i++){
            for(j = 0; j < bcolumns; j++){
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}