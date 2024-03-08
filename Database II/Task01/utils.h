#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Checks if the file is empty,return -1 if true
int emptyFile(FILE *file);

//Print the entire entry file
void printEntryFile(FILE *file);

//Print the entire physical file in a table;
void printPhysicalFile(FILE *file);

//Aux function that checks if the argv is on table.dic.Returns 1 if true and 0 if false
int isOnEntryFile(FILE *file, char *userLogicalName);