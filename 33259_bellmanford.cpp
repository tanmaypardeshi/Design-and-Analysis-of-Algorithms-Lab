#include <bits/stdc++.h>
using namespace std;

typedef struct edge
{
    int source;
    int destination;
    int weight;
} Edge;

typedef struct graph
{
    int vertices, edges;
    Edge *edge;
} Graph;

Graph *create(int v, int e)
{
    Graph *graph = new Graph;
    graph->vertices = v;
    graph->edges = e;
    graph->edge = new Edge[e];
    return graph;
}

void printPath(int parent[], int vertex)
{
    if (vertex < 0)
        return;
    printPath(parent, parent[vertex]);
    cout << vertex << " ";
}

void relax(int u, int v, int weight, int dist[], int parent[])
{
    if (dist[v] > dist[u] + weight)
    {
        dist[v] = dist[u] + weight;
        parent[v] = u;
    }
}

void bellman(Graph *graph, int src)
{
    int v = graph->vertices;
    int e = graph->edges;
    int *dist = new int[v];
    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT32_MAX;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int i = 1; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            relax(graph->edge[j].source, graph->edge[j].destination, graph->edge[j].weight, dist, parent);
        }
    }
    for (int i = 0; i < e; i++)
    {
        if (dist[graph->edge[i].destination] > dist[graph->edge[i].source] + graph->edge[i].weight)
        {
            cout << "\nNo solution" << endl;
            return;
        }
    }
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

    cout << endl;

    bellman(graph, 0);

    return 0;
}