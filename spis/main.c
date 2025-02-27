#include <stdio.h>
#include "book_mngr.c"


int main(){

    Book book1 = {"bogdan", "pierdek", 111};

    printf("%s\n", book1.author);
    

    return 0;
}