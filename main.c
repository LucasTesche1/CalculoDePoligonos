#include <stdio.h>
#include <stdlib.h>
#include "poligono.h"

int main()
{
    FILE *arquivo;
    int qntVertices;

    // Aqui é aberto o arquivo para leitura dos dados
    arquivo = fopen("vertices.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Aqui é lido o número de vértices
    fscanf(arquivo, "%d", &qntVertices);

    Point *vertices = (Point *)malloc(qntVertices * sizeof(Point));

    for (int i = 0; i < qntVertices; i++)
    {
        fscanf(arquivo, "%lf %lf", &(vertices[i].x), &(vertices[i].y));
    }

    fclose(arquivo);

    // Aqui é calculada e impressa a área do poligono
    double area = AreaPoligono(vertices, qntVertices);

    printf("A area do poligono e %.2lf\n", area);

    // Finalizamos liberando a memória
    free(vertices);

    return 0;
}