#include <iostream>
#include <limits.h>
using namespace std;


int minDistance(int dist[], bool sptSet[], int V) {    //dist[]=array to store dist of source vert to each vertex,sptSet[]=shortest path tree (vertex is included in spt or not)                  
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)                   //iterates over vertices
        if (sptSet[v] == false && dist[v] <= min) //not included in sptSet source vetex is less than min
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int **graph, int src, int V) {  //from source all vertices
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;      //distance of all vertices are unknown and no vertex include in sptSet

    dist[src] = 0;                  //initially source to vertex dist=0

    for (int count = 0; count < V - 1; count++) {         //except source vertex
        int u = minDistance(dist, sptSet, V);            //select vertex u
        sptSet[u] = true;                               //min distance =sptset add

        for (int v = 0; v < V; v++)                     //shortest path finad through u updates:
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int **graph = new int*[V];             //dynamically allocate memory for 2d array
    for (int i = 0; i < V; i++) 
    {
        graph[i] = new int[V];             
        cout << "Enter elements of row " << i << ": ";
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, src, V);

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}



