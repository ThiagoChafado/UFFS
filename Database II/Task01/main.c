#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf(("No args\n"));
        return 1;
    }

    // opening table.dic
    FILE *tableFile = fopen("table.dic", "r");
    int isEmpty = emptyFile(tableFile);
    if (isEmpty == -1)
    {
        printf("Empty File\n");
        return 1;
    }
    fclose(tableFile);

    tableFile = fopen("table.dic", "r");
    int aux = isOnEntryFile(tableFile, argv[1]);
    if (aux == 0)
    {
        printf("No table with name '%s'\n", argv[1]);
        return 1;
    }
    fclose(tableFile);

    tableFile = fopen("table.dic", "r");
    EntryFile tableStruct = getEntryStruct(tableFile, argv[1]);

    fclose(tableFile);

    FILE *attFile = fopen("att.dic", "rb");
    int numStructs = 0;
    PhysicFile *physicStruct = getPhysicStruct(attFile, tableStruct.id, &numStructs);
    char fileName[60];
    sprintf(fileName, "%s", tableStruct.physicalName);
    FILE *datFile = fopen(fileName, "rb");
    if (datFile == NULL){
        printf("No dat file with name '%s'\n",tableStruct.physicalName);
        return 1;
    }

    //Trying to make a table
    for (int i = 0; i < numStructs; i++) {
        printf("%-*s | ", physicStruct[i].attSize, physicStruct[i].attName);
    }
    printf("\n");

    fclose(datFile);
    datFile = fopen(fileName, "rb");
    printDatFile(datFile, physicStruct, numStructs);
    fclose(datFile);

    return 0;
}