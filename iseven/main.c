#include <stdio.h>
#include "libeven.h"

bool is_even(int number);

int main(){

    int num;
    is_even(num);
    printf("Enter number: ");
    scanf("%d", &num);

    if (is_even(num) == true){
        printf("%d is even", num);
    }
    else{ 
        printf("%d is odd", num);
    }
    return 0;
}

