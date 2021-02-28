#ifndef SELECTION_H
#define SELECTION_H

int neighbours( int, int**, int*, int, int);
void selection( int, int**, int*, char**, char**, char**, int, int*);
int colors(int, int*, int);
int country_check_colors(  int, int*, int**, char**);
int check( int, int*, int, char**, char**, int, int, int**);


#endif
