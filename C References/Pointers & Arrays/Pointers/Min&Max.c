#include<stdio.h>

void minMax(int arr[], int len, int *min, int *max){
    *min = *max = arr[0];

    for(int i = 1; i < len; i++){
        if(arr[i] < *min){
            *min = arr[i];
        }
        if(arr[i] > *max){
            *max = arr[i];
        }
    }
}

// It is not possible to return more than one variable/value to the main function. That's why I've used void type.

int main(){
    int len, min, max;
    printf("Enter the length of array: ");
    scanf("%d", &len);

    int arr[len];
    for(int i=0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    minMax(arr, len, &min, &max);
    printf("Minimum and Maximum value of the array is %d, %d.", min, max);
    return 0;
}