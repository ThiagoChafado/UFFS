#include "utils.h"

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

int emptyFile(FILE *file)
{
    int c = fgetc(file);
    if (c == EOF)
    {
        return -1;
    }
}

int isOnEntryFile(FILE *file, char *userLogicalName){
    EntryFile buffer;
    while(fread(&buffer,sizeof(EntryFile),1,file) == 1){
        int equal = strcmp(userLogicalName,buffer.logicalName);
        if(equal == 0){
            return 1;
        }
    }
    return 0;
}

void printPhysicalFile(FILE *file)
{
    PhysicFile buffer;
    while(fread(&buffer,sizeof(PhysicFile),1,file) == 1){
        printf("ID: %d\n",buffer.id);
        printf("Atribute name: %s\n",buffer.attName);
        printf("Atribute type: %c\n",buffer.attType);
        printf("Is opt?: %d\n",buffer.isOpt);
        printf("Atribute size: %d\n",buffer.attSize);
        printf("\n");
    }
}

void printEntryFile(FILE *file)
{
    EntryFile buffer;

    while (fread(&buffer, sizeof(EntryFile), 1, file) == 1)
    {

        printf("ID: %d\n", buffer.id);
        printf("Logical Name: %s\n", buffer.logicalName);
        printf("Physical Name: %s\n", buffer.physicalName);
        printf("\n");
    }
}