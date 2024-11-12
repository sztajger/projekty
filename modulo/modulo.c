#include <stdint.h>

void modulo();

int main (void)
{
    modulo();
    return 0 ;
}

void modulo() {

int a;
printf("Enter number: ");
scanf("%d", &a);

if (a % 2 > 0)
    printf("%d is even", a);

else 
    printf("%d is odd", a);

    
}