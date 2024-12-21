#include<stdio.h>

int *findMid(int arr[], int len){
    return &arr[len/2];
}
int main(){
    int len;
    printf("Enter the length of array: ");
    scanf("%d", &len);

    int arr[len];
    for(int i=0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    int *mid = findMid(arr, len);
    printf("%d", *mid);
    return 0;
}

// Never ever try to return pointer of automatic variable(local variable).
/*
int function(){
    int i=1;
    return i++;
}
here i is declared and initialized in a function scoope. so it is a automatic variable.
*/