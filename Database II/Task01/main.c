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
        printf("No table %s\n", argv[1]);
        return 1;
    }
    fclose(tableFile);

    // printEntryFile(tableFile);
    // printf("=========\n");

    // FILE *attFile = fopen("att.dic","rb");
    // printPhysicalFile(attFile);

    return 0;
}