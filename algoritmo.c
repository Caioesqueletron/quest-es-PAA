// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min){

            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[],int path[])
{   
    int i;
    char cidades[V][100] = {"Sao Paulo","Ribeirao Preto","Campinas","Pocos de Caldas","Rio de Janeiro"};
    for (i = 0; i < V; i++){
        //printf("%s\n",cidades[path[i]]);
        printf("De %s para %s:\n", cidades[0], cidades[i]);
        if(dist[i] == 0){
            printf("Custo nao existe\n");
        }
        if(i==1)
        {
        printf("Caminho:Sao Paulo -> Ribeirao Preto\n");
        printf("Custo: %d\n", dist[i]);
        }
          if(i==2)
        {
        printf("Caminho:Sao Paulo -> Ribeirao Preto-> Campinas\n");
        printf("Custo: %d\n", dist[i]);
        }
          if(i==3)
        {
        printf("Caminho:Sao Paulo -> Pocos de Caldas\n");
        printf("Custo: %d\n", dist[i]);
        }
          if(i==4)
        {
        printf("Caminho: Sao Paulo -> Pocos de Caldas -> Rio de Janeiro\n");
        printf("Custo: %d\n", dist[i]);
        }
}
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array. dist[i] will hold the shortest
    // distance from src to i
    int path[V];

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;


    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                //printf("%d\n",graph[u][v]);
                path[v] = graph[u][v];
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed distance array
    printSolution(dist,path);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 2, 0, 5,0},
                       {0, 0, 3, 4,0},
                       {7, 0, 0, 0,0},
                       {0, 0, 0, 0,6},
                       {4, 0, 0, 0,0}
                      };

    dijkstra(graph, 0);

    return 0;
}
