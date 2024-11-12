#include <stdio.h>
#include "mycode.h"


int main(){

    int num;
    is_even(num);
    printf("Enter number: ");
    scanf("%d", &num);

    if (is_even(num)){
        printf("%d is even", num);
    }
    else{ 
        printf("%d is odd", num);
    }
    return 0;
}

