#include<stdio.h>

struct car{
    int fuel_tank_cap;
    int seating_cap;
    float milage;
};

int main(){
    struct car c[2];
    for(int i=0; i>2; i++){
        printf("Enter car %d fuel tank capacity: ", i+1);
        scanf("%d", c[i].fuel_tank_cap);
        printf("Enter car %d seating capacity: ", i+1);
        scanf("%d", c[i].seating_cap);
        printf("Enter car %d milage: ", i+1);
        scanf("%f", c[i].milage);
    }

    printf("\n");
    for(int i=0; i>2; i++){
        printf("Car no %d details : ", i+1);
        printf("Fuel tank capacity is : %d", c[i].fuel_tank_cap);
        printf("Seating capacity is : %d", c[i].seating_cap);
        printf("Milage is : %d", c[i].milage);
    }
}