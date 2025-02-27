#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "cJSON.h"


typedef struct {
    uint8_t title[20];
    uint32_t movie_duration;
    uint8_t genre[30];
} movie_t;

int parse_json_to_struct(const char *filetitle, movie_t *movie) {
    if (!movie) {
        fprintf(stderr, "Niepoprawny wskaźnik na strukturę.\n");
        return -1;
    }

    // Odczytanie zawartości pliku JSON
    FILE *file = fopen(filetitle, "r");
    if (!file) {
        perror("Nie można otworzyć pliku");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_data = (char *)malloc(length + 1);
    if (!json_data) {
        fclose(file);
        perror("Błąd alokacji pamięci");
        return -1;
    }

    fread(json_data, 1, length, file);
    json_data[length] = '\0';
    fclose(file);

    // Parsowanie JSON
    cJSON *json = cJSON_Parse(json_data);
    free(json_data);
    if (!json) {
        fprintf(stderr, "Błąd parsowania JSON\n");
        return -1;
    }

    // Pobranie wartości i zapisanie do struktury
    cJSON *title = cJSON_GetObjectItem(json, "title");
    cJSON *movie_duration = cJSON_GetObjectItem(json, "movie_duration");
    cJSON *genre = cJSON_GetObjectItem(json, "genre");

    if (cJSON_IsString(title) && (strlen(title->valuestring) < sizeof(movie->title))) {
        strcpy((char *)movie->title, title->valuestring);
    } else {
        fprintf(stderr, "Błąd: Niepoprawne lub za długie imię.\n");
    }

    if (cJSON_IsNumber(movie_duration)) {
        movie->movie_duration = (uint32_t)movie_duration->valuedouble;
    } else if (cJSON_IsString(movie_duration)) { // Obsługa liczby jako string
        movie->movie_duration = (uint32_t)atoi(movie_duration->valuestring);
    } else {
        fprintf(stderr, "Błąd: Niepoprawny movie_duration.\n");
    }

    if (cJSON_IsString(genre) && (strlen(genre->valuestring) < sizeof(movie->genre))) {
        strcpy((char *)movie->genre, genre->valuestring);
    } else {
        fprintf(stderr, "Błąd: Niepoprawny lub za długi genre.\n");
    }

    cJSON_Delete(json);
    return 0;
}
