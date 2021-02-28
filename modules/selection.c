#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "selection.h"
#include "sorting.h"
#include "colors.h"

int neighbours(int counter, int **neighbours, int *color, int color1, int land)
{
        //check for all neighbours tis antistoixis corresponding land that insert with name as a variable land,
        //if have different color from its neighbors
        for (int i = 0; i < counter; i++)
        {
                //if exists one neighbours with the same color than we return zero(0)
                if (neighbours[land][i] == 1 && color[i] == color1)
                        return 0;
        }

        //we rerurn one(1) if this land have different color from all neighbours
        return 1;
}

void selection(int counter, int **matrix2, int *color, char **country, char **input_table, char **color_country, int input_table_size, int *Position)
{
        int correct_neighbours = 0;
        for (int i = 0; i < counter; ++i)
        {
                int f1 = 0;
                int f2 = 0;
                for (int j = 0; j < counter; ++j)
                {
                        if (matrix2[i][j] == 1)
                        {
                                f1++;

                                //i check if the map is correct colorising
                                if (color[i] != color[j])
                                        f2++;
                        }
                }

                //if the countries where accumulate is same with they where have different color than f++
                if (f1 == f2)
                        correct_neighbours++;
        }

        //if the f is different from counter than same countries have same color, therefore the map cann't colorising correct
        if ( correct_neighbours != counter)
        {
                fprintf(stderr, "the map can't be colored\n");
                Free(input_table, color_country, country, matrix2, input_table_size, counter);
                exit(0);
        }

        //i contructor the variable count_2 with zero(0)
        int count_2 = 0;
        int line;
        for (int i = 0; i <= input_table_size; ++i)
        {
                //i do one for loop for to print all word tha they is save in a table input_table
                for (int k = 0; k < counter; ++k)
                {       
                        //because the table st2 have sorting we must print the table input_table
                        //but with color
                        if (Position[k] == count_2)
                        {              
                                //With a table Position we find which element is and print the respectively
                                //k is the line where we want to print
                                line = k;
                                break;
                        }
                }
                if (strcmp(input_table[i], color_country[line]) == 0)
                {       
                        //If element the string from the table input_table, str2(the colors from country respectively) than we print than we print tha colors and not the names countries
                        if(i)printf("\n");
                        //check for to print the correct color
                        if (color[line] == 1)
                        {
                                printf("red  ");
                        } 
                        else if (color[line] == 2)
                        {
                                printf("green  ");
                        }
                        else if (color[line] == 3)
                        {
                                printf("blue  ");
                        }
                        else if (color[line] == 4)
                        {
                                printf("yellow  ");
                        }
                        else if (color[line] == 5)
                        {
                                printf("orange  ");
                        }
                        else if (color[line] == 6)
                        {
                                printf("violet ");
                        }
                        else if (color[line] == 7)
                        {
                                printf("cyan  ");
                        }
                        else if (color[line] == 8)
                        {
                                printf("pink  ");
                        }
                        else if (color[line] == 9)
                        {
                                printf("brown  ");
                        }
                        else if (color[line] == 10)
                        {
                                printf("grey  ");
                        }
                        //count_2++ for the next country
                        count_2++;
                }
                else
                {
                        if (i != input_table_size)
                        {
                                //print the names countries
                                printf("%s  ", input_table[i]);
                        }
                        else
                        {
                                printf("%s", input_table[i]);
                        }
                }
        }
        printf("\n");
        //free
        Free(input_table, color_country, country, matrix2, input_table_size, counter);

        exit(0);
}

//check if the map have coloring with number_colors colors
int colors(int color_size, int *color, int number_colors)
{
        int different_colors;
        int all_colors[12];
        int size_all_colors = 0;
        for (int i = 0; i <= color_size; ++i)
        {       
                //check for all elements for the table color
                if (i == 0)
                {       
                        //create a table with name all_colors where have all different colors
                        
                        //for example if the map have 5 colors than the table all_colors 
                        //will have 5 elements, which is the 5 colors from table color
                        all_colors[0] = color[0]; 
                }
                else
                {       
                        //count where meteres how many elements check where is different from color[i]
                        different_colors = 0;
                        for (int j = 0; j <= size_all_colors; ++j)
                        {       
                                //if this color is different drom all colors where have the table all_colors
                                if (color[i] != all_colors[j])
                                {       
                                        ++different_colors;
                                }
                        }
                        if (different_colors - 1 == size_all_colors)
                        {
                                all_colors[++size_all_colors] = color[i];
                        }
                }
        }
        
        //if the colors are more than those given from variable number_colors
        //when return 0 otherwise 1
        if (size_all_colors > number_colors - 1)
        {
                return 0;
        }
        return 1;
}

//she fuction check if all countries have differents colors from their neighbors
int country_check_colors(int counter, int *color, int **matrix, char **country) 
{ 
        bool check = false;
        for (int i = 0; i < counter; ++i)
        {
                for (int j = 0; j < counter; ++j)
                {
                        if (matrix[i][j] == 1)
                        {
                                if (color[i] == color[j])
                                {       
                                        //check the neighbours
                                        fprintf( stderr, RED "%s-%s:Should have different color\n" RESET , country[i], country[j]);
                                        check = true;
                                }
                        }
                }
        }

        //if check#true, that all neighbours have different colors and i return zero(0), otherwise return one(1)
        if (check == true)
        {
                return 1;
        }
        return 0;
}

int check(int color_size, int *color, int count, char **country, char **input_table, int input_table_size, int number_colors, int **matrix) //i sinartisi elegxos kaleitai apo to -c poy dinei o xristis gia na elenksei enan xromatismeno xarti
{
        if (colors(color_size, color, number_colors) == 0)
        {   
                //if the fuction colors return 1, than the map have 
                //colorising with max 4 colors, otherwise print the message
                fprintf( stderr, RED "More than %d colors used\n" RESET , number_colors);
                return 0;
        }

        if (country_check_colors(count, color, matrix, country))
        { 
                //if the fuction country_check_colors return one(1) the map isn't correct colorising
                return 1;
        }

        //the map is correct colored
        fprintf( stderr, GREEN "The map has been colored correctly\n" RESET);
        return 0;
}
