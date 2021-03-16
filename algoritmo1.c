#include <stdio.h>
#include <stdlib.h>
//inf valor que iniciará cada vertice
#define INF 99999

#define Vertices 5

void dijkstra(int grafo[Vertices][Vertices], int n, int source);

int main()
{

    /* Criando o grafo relacionado ao exercicio */
    int grafo[Vertices][Vertices] = {
        {0, 2, 0, 5, 0},
        {0, 0, 3, 4, 0},
        {7, 0, 0, 0, 0},
        {0, 0, 0, 0, 6},
        {4, 0, 0, 0, 0}};

    // executa a função de dijkstra
    dijkstra(grafo, Vertices, 0);

    return 0;
}

void dijkstra(int grafo[Vertices][Vertices], int n, int source)
{
    int custo[Vertices][Vertices], distancia[Vertices], visitados[Vertices], sucessor[Vertices];
    int i, j, count, mindistancia, prox;
    char cidades[Vertices][20] = {"Sao Paulo", "Ribeirao Preto", "Campinas", "Pocos de Caldas", "Rio de Janeiro"};

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (grafo[i][j] == 0)
            {
                custo[i][j] = INF;
            }
            else
            {
                custo[i][j] = grafo[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        distancia[i] = custo[source][i];
        sucessor[i] = source;
        visitados[i] = 0;
    }

    distancia[source] = 0;
    visitados[source] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindistancia = INF;
        for (i = 0; i < n; i++)
        {
            if (distancia[i] < mindistancia && !visitados[i])
            {
                mindistancia = distancia[i];
                prox = i;
            }
        }

        visitados[prox] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visitados[i])
            {
                if ((mindistancia + custo[prox][i]) < distancia[i])
                {
                    distancia[i] = mindistancia + custo[prox][i];
                    sucessor[i] = prox;
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++)
    {
        if (i == source)
        {
            printf("De %s para %s:Não existe\n", cidades[source], cidades[i]);
            printf("Custo:-\n");
        }
        if (i != source)
        {
            printf("De %s para %s: %s", cidades[source], cidades[i], cidades[source]);
            j = i;
            do
            {
                j = sucessor[j];
                if (j != 0)
                {

                    printf("->%s", cidades[j]);
                }
                else{
                     printf("->%s", cidades[i]);
                }
            } while (j != source);
            printf("\n");
            printf("Custo:%d\n", distancia[i]);
        }
    }
}