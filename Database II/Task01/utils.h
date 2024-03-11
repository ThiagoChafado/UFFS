#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char logicalName[20];
    char physicalName[20];
} EntryFile;

typedef struct
{
    int id;
    char attName[20];
    char attType;
    char isOpt;
    int attSize;
} PhysicFile;



//Checks if the file is empty,return -1 if true
int emptyFile(FILE *file);

//Print the entire entry file
void printEntryFile(FILE *file);

//Print the entire physical file in a table;
void printPhysicalFile(FILE *file);

//Aux function that checks if the argv is on table.dic.Returns 1 if true and 0 if false
int isOnEntryFile(FILE *file, char *userLogicalName);

//Aux function that returns the struct and data from the table.dic
EntryFile getEntryStruct(FILE *file,char *userLogicalName);

//Aux function that returns an array os structs from the physic file
PhysicFile* getPhysicStruct(FILE *file,int id, int *numStructs);

//Aux function to print data from dat file using offset 
void printDatFile(FILE *file, PhysicFile *datStruct, int numStructs);