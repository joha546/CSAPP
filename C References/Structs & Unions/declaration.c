#include<stdio.h>
#include<stdlib.h>

struct{
    char *engine;
}car1,car2;

int main(){

    // Allocate memory for the engine names.
    car1.engine = (char*)malloc(100 * sizeof(char));
    car2.engine = (char*)malloc(100*sizeof(char));
    printf("Enter car1 Name: ");
    scanf("%s", car1.engine);
    printf("Enter car2 Name: ");
    scanf("%s", car2.engine);

    printf("%s\n", car1.engine);
    printf("%s\n", car2.engine);

    // Free allocated memory
    free(car1.engine);
    free(car2.engine);
    return 0;
}