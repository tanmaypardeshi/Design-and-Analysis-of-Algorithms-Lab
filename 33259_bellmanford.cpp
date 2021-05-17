#include <bits/stdc++.h>
using namespace std;

// Structure for Edge
typedef struct edge
{
    int source;
    int destination;
    int weight;
} Edge;

// Structure for Graph
typedef struct graph
{
    int vertices, edges;
    Edge *edge;
} Graph;

// Create graph
Graph *create(int v, int e)
{
    Graph *graph = new Graph;
    graph->vertices = v;
    graph->edges = e;
    graph->edge = new Edge[e];
    return graph;
}

// Print the path of from source till the destination
void printPath(int parent[], int vertex)
{
    if (vertex < 0)
        return;
    printPath(parent, parent[vertex]);
    cout << vertex << " ";
}

// Relaxation process
void relax(int u, int v, int weight, int dist[], int parent[])
{
    if (dist[v] > dist[u] + weight)
    {
        dist[v] = dist[u] + weight;
        parent[v] = u;
    }
}

// Bellman ford algorithm
void bellman(Graph *graph, int src)
{
    // Initialise vertices and edges
    int v = graph->vertices;
    int e = graph->edges;
    int *dist = new int[v];
    int *parent = new int[v];

    // Initialise distance and parent matrix
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT32_MAX;
        parent[i] = -1;
    }
    // Distance of source is always 0
    dist[src] = 0;

    // Iterate the graph v - 1 times and relax all edges
    for (int i = 1; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            relax(graph->edge[j].source, graph->edge[j].destination, graph->edge[j].weight, dist, parent);
        }
    }

    // Iterate vth time and see if it is still relaxing. If yes, then a negative cycle is found.
    for (int i = 0; i < e; i++)
    {
        if (dist[graph->edge[i].destination] > dist[graph->edge[i].source] + graph->edge[i].weight)
        {
            cout << "Negative cycle found" << endl;
            return;
        }
    }

    // If negative cycle is not found, print the distance of vertex from source and the path using printPath()
    for (int i = 0; i < v; i++)
    {
        cout << "Distance from source is:- " << dist[i];
        cout << ". The path is:- ";
        printPath(parent, i);
        cout << endl;
    }
}

int main()
{
    // Input and create the graph
    int v, e;
    cout << "Enter the number of vertices:- ";
    cin >> v;
    cout << "Enter the number of edges:- ";
    cin >> e;

    Graph *graph = create(v, e);

    for (int i = 0; i < e; i++)
    {
        cout << "\nEnter source for edge " << i + 1 << ":- ";
        cin >> graph->edge[i].source;
        cout << "Enter destination for edge " << i + 1 << ":- ";
        cin >> graph->edge[i].destination;
        cout << "Enter weight for edge " << i + 1 << ":- ";
        cin >> graph->edge[i].weight;
    }

    // Display the graph
    cout << "\nGraph is:- \n"
         << endl;
    for (int i = 0; i < e; i++)
    {
        cout << "(" << graph->edge[i].source << "," << graph->edge[i].destination << ") -> " << graph->edge[i].weight << endl;
        cout << endl;
    }

    bellman(graph, 0);

    return 0;
}

/* Output :- 

tanmay@Predator:~/Code/DAA$ g++ 33259_bellmanford.cpp 
tanmay@Predator:~/Code/DAA$ ./a.out 
Enter the number of vertices:- 7
Enter the number of edges:- 10

Enter source for edge 1:- 0
Enter destination for edge 1:- 1
Enter weight for edge 1:- 6

Enter source for edge 2:- 0
Enter destination for edge 2:- 2
Enter weight for edge 2:- 5

Enter source for edge 3:- 0
Enter destination for edge 3:- 3
Enter weight for edge 3:- 5

Enter source for edge 4:- 1
Enter destination for edge 4:- 4
Enter weight for edge 4:- -1

Enter source for edge 5:- 2
Enter destination for edge 5:- 1
Enter weight for edge 5:- -2

Enter source for edge 6:- 2
Enter destination for edge 6:- 4
Enter weight for edge 6:- 1

Enter source for edge 7:- 3
Enter destination for edge 7:- 2
Enter weight for edge 7:- -2

Enter source for edge 8:- 3
Enter destination for edge 8:- 5
Enter weight for edge 8:- -1

Enter source for edge 9:- 5
Enter destination for edge 9:- 6
Enter weight for edge 9:- 3

Enter source for edge 10:- 4
Enter destination for edge 10:- 6
Enter weight for edge 10:- 3

Graph is:- 

(0,1) -> 6

(0,2) -> 5

(0,3) -> 5

(1,4) -> -1

(2,1) -> -2

(2,4) -> 1

(3,2) -> -2

(3,5) -> -1

(5,6) -> 3

(4,6) -> 3

Distance from source is:- 0. The path is:- 0 
Distance from source is:- 1. The path is:- 0 3 2 1 
Distance from source is:- 3. The path is:- 0 3 2 
Distance from source is:- 5. The path is:- 0 3 
Distance from source is:- 0. The path is:- 0 3 2 1 4 
Distance from source is:- 4. The path is:- 0 3 5 
Distance from source is:- 3. The path is:- 0 3 2 1 4 6 

tanmay@Predator:~/Code/DAA$ ./a.out 
Enter the number of vertices:- 4
Enter the number of edges:- 4

Enter source for edge 1:- 0
Enter destination for edge 1:- 1
Enter weight for edge 1:- 1

Enter source for edge 2:- 1
Enter destination for edge 2:- 2
Enter weight for edge 2:- -1

Enter source for edge 3:- 2
Enter destination for edge 3:- 3
Enter weight for edge 3:- -1

Enter source for edge 4:- 3
Enter destination for edge 4:- 0
Enter weight for edge 4:- -1

Graph is:- 

(0,1) -> 1

(1,2) -> -1

(2,3) -> -1

(3,0) -> -1

Negative cycle found
*/