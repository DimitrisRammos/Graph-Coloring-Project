#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "selection.h"
#include "sorting.h"
#include "colors.h"

#define ERROR -1

//main program
int main(int argc, char *argv[])
{

        FILE *fptr;
        // char or2[] = "-i";
        fptr = fopen(argv[2], "r");
        
        //save the inut from txt
        char **input_table;
        input_table = malloc(1 * sizeof(char *));
        if (input_table == NULL)
        {
                return ERROR;
        }

        //read
        //I believe that there is no greater word from 20 characters
        int input_table_size = 0;
        input_table[0] = (char *)malloc(21);
        if (input_table[0] == NULL)
        {
                free( input_table);
                return ERROR;
        }

        //we create a table with colors
        char **color_country;
        color_country = malloc(1 * sizeof(char *));
        if (color_country == NULL)
        {
                free(input_table[0]);
                free( input_table);
                return ERROR;
        }

        //for color_country
        int color_country_size = 0;
        color_country[0] = (char *)malloc(21);
        if (color_country[0] == NULL)
        {
                free(input_table[0]);
                free( input_table);
                free(color_country);
                return ERROR;
        }

        //count
        int count = 0;

        //create a table with countries
        char **country; 
        country = malloc(1 * sizeof(char *));
        if (country == NULL)
        {
                free( input_table[0]);
                free( input_table);
                free( color_country[0]);
                free( color_country);
                return ERROR;
        }
        
        //for country
        country[0] = (char *)malloc(21);
        if (country[0] == NULL)
        {
                free( input_table[0]);
                free( input_table);
                free( color_country[0]);
                free( color_country);
                free( country);
                return ERROR;
        }

        //read the txt
        if (fptr != NULL)
        {
                //open file from input
                while (fscanf(fptr, "%s", input_table[input_table_size]) != EOF)
                {
                        input_table_size++;

                        //for every new word  we  make  board bigger by one index
                        input_table = realloc(input_table, (input_table_size + 1) * sizeof(char *));
                        if ( input_table == NULL)
                        {
                                return ERROR;
                        }

                        //we store a word of maximum 20 letters
                        input_table[input_table_size] = (char *)malloc(21);
                        if (input_table[input_table_size] == NULL)
                        {
                                return ERROR;
                        }
                }
                input_table_size--;
                fclose(fptr);   //close file

                //open file and read file but this time
                //i save the first word from every line
                fptr = fopen(argv[2], "r");
                
                while (fscanf(fptr, "%s%*[^\n]", color_country[color_country_size]) != EOF)
                { 
                        //the first word from every line have the color for this country
                        color_country_size++;
                        color_country = realloc(color_country, (color_country_size + 1) * sizeof(char *)); /*for every new word  we  make  board bigger by one index*/
                        if (color_country == NULL)
                        {
                                return ERROR;
                        }
                        color_country[color_country_size] = (char *)malloc(21); /* we store a word of maximum 20 letters*/
                        if (color_country[color_country_size] == NULL)
                        {
                                return ERROR;
                        }
                }
                color_country_size--;
                fclose(fptr);
                for (int i = 0; i <= input_table_size; i++)
                {
                        if (strcmp(input_table[i], color_country[count]) == 0)
                        {
                                if (count == 0)
                                        strcpy(country[count], input_table[i + 1]); //kanoume i+1 dioti i epomeni leji meta to xroma  einai i xwra
                                else
                                {
                                        country = realloc(country, (count + 1) * sizeof(char *));
                                        if (country == NULL)
                                        {
                                                return ERROR;
                                        }
                                        country[count] = (char *)malloc(21);
                                        if (country[count] == NULL)
                                        {
                                                return ERROR;
                                        }
                                        strcpy(country[count], input_table[i + 1]);
                                }
                                count++; /*for every different country we increase count so we can create an extra index*/
                        }
                }
        }
        else
        {       
                //if we read from entrance redirection 
                FILE *fp2;
                FILE *fp;

                //i save in 2 files for to read 2 times
                fp = fopen("input.txt", "w");
                char ch;
                ch = fgetc(stdin);

                while (ch != EOF)
                {       
                        //we print in input.txt for to process it
                        fprintf(fp, "%c", ch);
                        ch = fgetc(stdin);
                }
                fclose(fp);

                //open input.txt
                fp2 = fopen("input.txt", "r");
                while (fscanf(fp2, "%s", input_table[input_table_size]) != EOF)
                {
                        input_table_size++;

                        //for every new word  we  make  board bigger by one index
                        input_table = realloc(input_table, (input_table_size + 1) * sizeof(char *)); 
                        if (input_table == NULL)
                        {
                                return ERROR;
                        }

                        //we store a word of maximum 20 letters
                        input_table[input_table_size] = (char *)malloc(21);
                        if (input_table[input_table_size] == NULL)
                        {
                                return ERROR;
                        }
                }
                input_table_size--;
                fclose(fp2);

                //open n.txt
                fp2 = fopen("input.txt", "r");
                while (fscanf(fp2, "%s%*[^\n]", color_country[color_country_size]) != EOF)
                {
                        color_country_size++;

                        //for every new word  we  make  board bigger by one index
                        color_country = realloc(color_country, (color_country_size + 1) * sizeof(char *));
                        if (color_country == NULL)
                        {
                                return ERROR;
                        }

                        //we store a word of maximum 20 letters
                        color_country[color_country_size] = (char *)malloc(21);
                        if (color_country[color_country_size] == NULL)
                        {
                                return ERROR;
                        }
                }
                color_country_size--;
                fclose(fp2);

                //for country
                for (int i = 0; i <= input_table_size; i++)
                {
                        if (strcmp(input_table[i], color_country[count]) == 0)
                        {
                                if (count == 0)
                                        strcpy(country[count], input_table[i + 1]);
                                else
                                {
                                        country = realloc(country, (count + 1) * sizeof(char *));
                                        if (country == NULL)
                                        {
                                                return ERROR;
                                        }
                                        country[count] = (char *)malloc(21);
                                        if (country[count] == NULL)
                                        {
                                                return ERROR;
                                        }
                                        strcpy(country[count], input_table[i + 1]);
                                }

                                //for every different country we increase count so we can create an extra index
                                count++;
                        }
                }
        }
        
        //i constructor the color for colorising map in 4
        char nc = 4;

        //-n parameter
        char or3[] = "-n";
        for (int i = 1; i < argc; ++i)
        {
                if (strcmp(argv[i], or3) == 0)
                {
                        nc = atoi(argv[i + 1]); //-n 5
                }
        }

        //we make a squared board to store the neighbours of each country
        int **matrix1;
        matrix1 = malloc((count) * sizeof(int *));
        
        //i create table matix1
        if (matrix1 == NULL)
                return ERROR;
        else
        {
                for (int i = 0; i < count; i++)
                {
                        matrix1[i] = malloc((count) * sizeof(int));
                        if (matrix1[i] == NULL)
                                return ERROR;
                }
        }

        for (int i = 0; i < count; i++)
        {
                for (int j = 0; j < count; j++)
                {       
                        //i constructor in zero(0)
                        matrix1[i][j] = 0;
                }
        }
        int gram = 0;
        int t = 0;
        for (int i = 1; i <= input_table_size; ++i)
        {
                //we start from 1 because the first word is a color
                if (strcmp(input_table[i - 1], color_country[t]) == 0)
                {
                        for (int j = 0; j < count; ++j)
                        {
                                if (strcmp(input_table[i], country[j]) == 0)
                                        //we store the number of this country so we can tick the her neighbours into the matrix
                                        gram = j;
                        }
                }
                else if (strcmp(input_table[i], color_country[t + 1]) != 0)
                {       
                        //if the word is different the the color thath means it is a country
                        for (int j = 0; j < count; ++j)
                        {
                                if (strcmp(input_table[i], country[j]) == 0)
                                {
                                        matrix1[gram][j] = 1;
                                        break;
                                }
                        }
                }
                else
                {
                        ++t;
                }
        }

        //we save position for every country
        int number[count], Position[count];
        for (int i = 0; i < count; ++i)
        {
                number[i] = 0;
                Position[i] = i;
                for (int j = 0; j < count; ++j)
                {
                        if (matrix1[i][j])
                        {       
                                //we save number neighbors
                                number[i]++;
                                Position[i] = i;
                        }
                }
        }

        int flag11 = 0;
        //if nocolor
        for (int i = 0; i < count; i++)
        {
                if (strcmp(color_country[i], "nocolor") == 0)
                {
                        //at least one country has no color
                        flag11 = 1;
                } 
        }


        if (flag11 == 1)
        {       
                //if the map has all ready been colored we dodnt have to sort the map
                sort(number, count, country, Position, color_country);
        }

        //we make a squared board to store the neighbours of each country
        int **matrix;
        matrix = malloc((count) * sizeof(int *));
        
        if (matrix == NULL)
                return ERROR;
        else
        {
                for (int i = 0; i < count; i++)
                {
                        matrix[i] = malloc((count) * sizeof(int));
                        if (matrix[i] == NULL)
                                return ERROR;
                }
        }

        for (int i = 0; i < count; i++)
        {
                for (int j = 0; j < count; ++j)
                {
                        //i create a sorted matrix
                        matrix[i][j] = 0; 
                }
        }


        int g = 0;
        int st = 0;
        for (int i = 0; i < count; i++)
        {
                for (int j = 0; j < count; j++)
                {
                        if (matrix1[i][j])
                        {
                                for (int m = 0; m < count; ++m)
                                        if (i == Position[m])
                                        {       
                                                //save the line
                                                g = m;
                                                break;
                                        }
                                for (int k = 0; k < count; k++)
                                        if (j == Position[k])
                                        {       
                                                //save the stele
                                                st = k;
                                                break;
                                        }
                                matrix[g][st] = 1;
                        }
                }
        }


        for (int i = 0; i < count; ++i)
        {
                free(matrix1[i]);
        }
        free(matrix1);
        for (int i = 0; i < count; i++)
        {
                for (int j = 0; j < count; j++)
                {
                        if (matrix[i][j] != matrix[j][i])
                        {
                                fprintf(stderr,RED "This map is wrong\n" RESET);
                                Free(input_table, color_country, country, matrix, input_table_size, count);
                                return ERROR;
                        }
                }
        }

        //the color for map
        char *color_2[] = {"red", "green", "blue", "yellow", "orange", "violet", "cyan", "pink", "brown", "grey"};
        int prec[count];
        int color[count];

        for (int i = 0; i < count; i++)
        {
                color[i] = 0;
                prec[i] = 0;
        }

        //how many countries have color
        int p1 = 0;
        for (int i = 0; i < count; ++i)
        {       
                //for the color that have a table color_country give cirresponding number
                if (strcmp(color_country[i], color_2[0]) == 0)
                {
                        color[i] = 1;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[1]) == 0)
                {
                        color[i] = 2;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[2]) == 0)
                {
                        color[i] = 3;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[3]) == 0)
                {
                        color[i] = 4;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[4]) == 0)
                {
                        color[i] = 5;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[5]) == 0)
                {
                        color[i] = 6;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[6]) == 0)
                {
                        color[i] = 7;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[7]) == 0)
                {
                        color[i] = 8;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[8]) == 0)
                {
                        color[i] = 9;
                        p1++;
                }
                else if (strcmp(color_country[i], color_2[9]) == 0)
                {
                        color[i] = 10;
                        p1++;
                }
                if (color[i] != 0)
                {       
                        //if the country have color i save which countries for don't change the name
                        prec[i] = 1;
                }
        }

        //-c parametre
        int ls = 0;
        char or [] = "-c";

        for (int i = 1; i < argc; ++i)
        {
                if (strcmp(argv[i], or) == 0)
                {
                        if (p1 == count)
                                ls = 2;
                        else if (p1 == 0)
                        {
                                fprintf(stderr, RED "Pleaze ,color the map first\n" RESET);
                                Free( input_table, color_country, country, matrix, input_table_size, count);
                                return ERROR;
                        }
                        else
                                ls = 1;
                }
        }

        //Colorising the map

        if (p1 > 0 && ls != 2)
        { 
                //if a table is precolored
                if (ls != 2)
                { 
                        //parially colored
                        int last;
                        int land = 0;
                        while (land < count && land >= 0)
                        { 
                                //The countries start from zero(0) for it we go until (count-1)
                                last = color[land]; //save the previous color

                                if (prec[land] == 0)
                                {       
                                        //if havn't color from the input
                                        if (last == 0)
                                        {       
                                                //if the country havn't color we started from the beginning
                                                for (int c = 1; c <= nc; c++)
                                                { 
                                                        //we see 1-1 the colors
                                                        if (neighbours(count, matrix, color, c, land) == 1 && c != last)
                                                        {
                                                                color[land] = c;
                                                                break;
                                                        } //check the colors from neighbours
                                                }
                                        }
                                        else
                                        {
                                                //if have color from previous and we want to check other color( backtracking)
                                                for (int c = last; c <= nc; c++)
                                                {       
                                                        //Start from the number color where have for  so as not to put colors
                                                        //that check this and isn't so good

                                                        if (neighbours(count, matrix, color, c, land) == 1 && c != last)
                                                        {
                                                                color[land] = c;
                                                                break;
                                                        }
                                                }
                                        }
                                }

                                //if this land have same color, we must go in the previous country, because this country can'y change the color
                                if (color[land] == last && prec[land] == 0)
                                        color[land] = 0; 
                                
                                if (color[land] == 0)
                                {
                                        land--;
                                        while (prec[land] == 1)
                                        {
                                                //if have color from input file don't change the color for country
                                                land--;
                                        } 
                                }
                                else
                                {
                                        land++;
                                        while (prec[land] == 1)
                                                land++;
                                }
                        }

                        //we can not print this map
                        if (color[0] == 0)
                        {
                                fprintf(stderr, RED "We can not print this map\n" RESET);
                                Free( input_table, color_country, country, matrix, input_table_size, count);
                                return ERROR;
                        }
                }
                if (ls == 0)
                {       //the map give us patrially colored and must to print
                        selection( count, matrix, color, country, input_table, color_country, input_table_size, Position);
                }
        }
        if (p1 == 0)
        {       
                //if one land havn't color
                int last;
                int land = 0;

                while (land < count && land >= 0)
                {
                        last = color[land];
                        if (last == 0)
                        {
                                for (int c = 1; c <= nc; c++)
                                {

                                        if (neighbours(count, matrix, color, c, land) == 1 && c != last)
                                        {
                                                color[land] = c;
                                                break;
                                        }
                                }
                        }
                        else
                        {
                                for (int c = last; c <= nc; c++)
                                {

                                        if (neighbours(count, matrix, color, c, land) == 1 && c != last)
                                        {
                                                color[land] = c;
                                                break;
                                        }
                                }
                        }
                        if (color[land] == last)
                                color[land] = 0;
                        if (color[land] == 0)
                                land--;
                        else
                                land++;
                }
                if (color[0] == 0)
                {
                        fprintf(stderr, RED "We can not print this map\n" RESET);
                        Free( input_table, color_country, country, matrix, input_table_size, count);
                        return ERROR;
                }
        }
        if (ls == 0)
        {
                selection(count, matrix, color, country, input_table, color_country, input_table_size, Position);
        }
        if (ls != 0)
        {       
                //the map have colorising and must to check
                check(color_country_size, color, count, country, input_table, input_table_size, nc, matrix);
                Free( input_table, color_country, country, matrix, input_table_size, count);
                return 0;
        }
}