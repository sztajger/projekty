#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

void read_json_data(const char *filename)
{

     // open the file 
   FILE *fp = fopen(filename, "r"); 
   if (fp == NULL) { 
       printf("Error: Unable to open the file.\n"); 
       return; 
   } 
 
   // read the file contents into a string 
   char buffer[1024]; 
   int len = fread(buffer, 1, sizeof(buffer), fp); 
   fclose(fp); 
 
   // parse the JSON data 
   cJSON *json = cJSON_Parse(buffer); 
   if (json == NULL) { 
       const char *error_ptr = cJSON_GetErrorPtr(); 
       if (error_ptr != NULL) { 
           printf("Error: %s\n", error_ptr); 
       } 
       cJSON_Delete(json); 
       return ; 
   } 
 
   // access the JSON data 
   cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "name"); 
   if (cJSON_IsString(name) && (name->valuestring != NULL)) { 
       printf("Name: %s\n", name->valuestring); 
   } 
 
   cJSON *email = cJSON_GetObjectItemCaseSensitive(json, "email"); 
   if (cJSON_IsString(email) && (email->valuestring != NULL)) { 
       printf("Email: %s\n", email->valuestring); 
   } 

   // delete the JSON object 
   cJSON_Delete(json); 
}