#include "utils.h"

int emptyFile(FILE *file)
{
    int c = fgetc(file);
    if (c == EOF)
    {
        return -1;
    }
}

int isOnEntryFile(FILE *file, char *userLogicalName)
{
    EntryFile buffer;
    while (fread(&buffer, sizeof(EntryFile), 1, file) == 1)
    {
        int equal = strcmp(userLogicalName, buffer.logicalName);
        if (equal == 0)
        {
            return 1;
        }
    }
    return 0;
}

void printPhysicalFile(FILE *file)
{
    PhysicFile buffer;
    while (fread(&buffer, sizeof(PhysicFile), 1, file) == 1)
    {
        printf("ID: %d\n", buffer.id);
        printf("Atribute name: %s\n", buffer.attName);
        printf("Atribute type: %c\n", buffer.attType);
        printf("Is opt?: %d\n", buffer.isOpt);
        printf("Atribute size: %d\n", buffer.attSize);
        printf("\n");
    }
}

EntryFile getEntryStruct(FILE *file, char *userLogicalName)
{
    EntryFile buffer;
    while (fread(&buffer, sizeof(EntryFile), 1, file) == 1)
    {
        int equal = strcmp(userLogicalName, buffer.logicalName);
        if (equal == 0)
        {
            return buffer;
        }
    }
}

PhysicFile *getDatStruct(FILE *file, int id, int *numStructs)
{
    PhysicFile *structures = malloc(100 * sizeof(PhysicFile));
    if (structures == NULL)
    {
        printf("Error on malloc!\n");
        return NULL;
    }
    PhysicFile buffer;
    int i = 0;
}

PhysicFile *getPhysicStruct(FILE *file, int id, int *numStructs)
{
    PhysicFile *structures = malloc(100 * sizeof(PhysicFile));
    if (structures == NULL)
    {
        printf("Error on malloc!\n");
        return NULL;
    }

    PhysicFile buffer;
    int i = 0;

    while (fread(&buffer, sizeof(PhysicFile), 1, file) == 1)
    {
        if (id == buffer.id)
        {
            structures[i] = buffer;
            i++;
        }
    }

    *numStructs = i;
    return structures;
}

void printDatFile(FILE *file, PhysicFile *datStruct, int numStructs)
{
    int recordSize = 0;
    for (int i = 0; i < numStructs; i++)
    {
        recordSize += datStruct[i].attSize;
    }

    char *record = malloc(recordSize * sizeof(char));
    while (fread(record, recordSize, 1, file) == 1)
    {
        int offset = 0;
        for (int i = 0; i < numStructs; i++)
        {
            if (datStruct[i].attType == 'S') {
                printf("%-*.*s | ", datStruct[i].attSize, datStruct[i].attSize, &record[offset]);
            } else if (datStruct[i].attType == 'I') {
                int intValue;
                memcpy(&intValue, &record[offset], sizeof(int));
                printf("%-*d | ", datStruct[i].attSize, intValue);
            } else if (datStruct[i].attType == 'D') {
                double doubleValue;
                memcpy(&doubleValue, &record[offset], sizeof(double));
                printf("%-*f | ", datStruct[i].attSize, doubleValue);
            }
            offset += datStruct[i].attSize;
            
        }
        printf("\n");
    }

    free(record);
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
