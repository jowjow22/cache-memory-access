#include <stdlib.h>
#include <stdio.h>

void storeNewTamFile(int increment)
{
    int currentTam;
    FILE *tamFile = fopen("tam.bin", "rb");
    fread(&currentTam, sizeof(int), 1, tamFile);
    fclose(tamFile);
    currentTam += increment;
    tamFile = fopen("tam.bin", "wb");
    fwrite(&currentTam, sizeof(int), 1, tamFile);
    fclose(tamFile);
}

void storeInitialTam(int tam)
{
    int storeTam = tam;
    FILE *tamFile = fopen("tam.bin", "wb");
    fwrite(&storeTam, sizeof(int), 1, tamFile);
    fclose(tamFile);
}

int readTamFile()
{
    int tam;
    FILE *tamFile = fopen("tam.bin", "rb");
    fread(&tam, sizeof(int), 1, tamFile);
    fclose(tamFile);
    return tam;
}

void clear()
{
    system("rm -f a.out tam.bin main perform");
}

int main()
{
    FILE *tamFile, *func1Max, *func2Max;
    storeInitialTam(0);
    int tam;
    system("rm data.csv");
    for (int i = 0; i <= 353; i++)
    {
        tam = readTamFile();

        system("gcc perform.c -w && ./a.out");

        storeNewTamFile(100);
    }

    system("gnuplot plot.gnu");

    clear();

    return 0;
}