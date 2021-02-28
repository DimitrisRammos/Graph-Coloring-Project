#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

void sort(int *number, int count, char **country, int *Position, char **color_country)
{  

   //sort the table
   int temp, temp2;
   char **temp1;
   //malloc
   temp1 = malloc(1 * sizeof(char *));
   temp1[0] = (char *)malloc(21);

   for (int i = 1; i < count; ++i)
   {
      for (int j = count - 1; j >= i; --j)
      {
         if (number[j] > number[j - 1])
         {
            temp = number[j];
            number[j] = number[j - 1];
            number[j - 1] = temp;
            strcpy(temp1[0], country[j]);
            strcpy(country[j], country[j - 1]);
            strcpy(country[j - 1], temp1[0]);
            strcpy(temp1[0], color_country[j]);
            strcpy(color_country[j], color_country[j - 1]);
            strcpy(color_country[j - 1], temp1[0]);
            temp2 = Position[j];
            Position[j] = Position[j - 1];
            Position[j - 1] = temp2;
         }
      }
   }

   free(temp1[0]);
   free(temp1);
}

//free the memory
void Free(char **input_table, char **color_country, char **country, int **matrix, int input_table_size, int count)
{

   //free the table input_file, color_country, country and matrix
   for (int i = 0; i <= (input_table_size + 1); ++i)
   {
      free(input_table[i]);
   }
   free( input_table);

   for (int i = 0; i < count; ++i)
   {
      free(color_country[i]);
   }
   free(color_country);

   for (int i = 0; i < count; ++i)
   {
      free(country[i]);
   }
   free(country);

   for (int i = 0; i < count; ++i)
   {
      free(matrix[i]);
   }
   free(matrix);
}
