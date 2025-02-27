#include <stdio.h>
#include "cJSON.h"
#include "cJSON.c"
#include "json_handler.h"





int main() {
    movie_t movie;
    if (parse_json_to_struct("data.json", &movie) == 0) {
        printf("Imie: %s\n", movie.title);
        printf("Wiek: %u\n", movie.movie_duration);
        printf("Email: %s\n", movie.genre);
    } else {
        printf("Błąd podczas parsowania JSON.\n");
    }
    return 0;
}