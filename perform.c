#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

struct pix
{
    unsigned int r, g, b;
} typedef pix;

struct pix *color;

int main()
{
    int TAM;
    FILE *fSizeTam;

    fSizeTam = fopen("tam.bin", "rb");
    fread(&TAM, sizeof(int), 1, fSizeTam);
    fclose(fSizeTam);

    color = (struct pix *)malloc(TAM * TAM * sizeof(struct pix));

    double ti, tf, tempo;

    ti = tf = tempo = 0;
    struct timeval tempo_inicio, tempo_fim;

    gettimeofday(&tempo_inicio, NULL);

    int i, j;

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            color[i * TAM + j].r =
                (color[i * TAM + j].r +
                 color[i * TAM + j].g +
                 color[i * TAM + j].b) /
                3;
        }
    }
    gettimeofday(&tempo_fim, NULL);
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
    tempo = (tf - ti) / 1000;

    double tempoFunc1;

    tempoFunc1 = tempo;

    FILE *fp = fopen("func1.tmp", "a");
    fprintf(fp, "%d %.5f\n", TAM, tempo);
    fclose(fp);

    gettimeofday(&tempo_inicio, NULL);

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            color[i * TAM + j].r =
                (color[j * TAM + i].r +
                 color[j * TAM + i].g +
                 color[j * TAM + i].b) /
                3;
        }
    }
    gettimeofday(&tempo_fim, NULL);
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
    tempo = (tf - ti) / 1000;

    fp = fopen("func2.tmp", "a");
    fprintf(fp, "%d %.5f\n", TAM, tempo);
    fclose(fp);

    fp = fopen("data.csv", "a");
    fprintf(fp, "%d,%.0f,%.0f\n", TAM, tempo, tempoFunc1);
    fclose(fp);

    return 0;
}