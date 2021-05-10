#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    int edges;
    int **graph;
    int *distance;
    bool *visited;

public:
    Graph() {}
    Graph(int, int);
    void create();
    void display();
    int findminvertex();
    void dijkstras();
};

Graph::Graph(int v, int e)
{
    vertices = v;
    edges = e;

    graph = new int *[v];
    for (int i = 0; i < v; i++)
    {
        graph[i] = new int[v];
    }

    distance = new int[v];
    visited = new bool[v];

    for (int i = 0; i < v; i++)
    {
        distance[i] = INT32_MAX;
        visited[i] = false;

        for (int j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }
    distance[0] = 0;
}

void Graph::create()
{
    int source, destination, weight;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source vertex:- ";
        cin >> source;
        cout << "Enter the destination vertex:- ";
        cin >> destination;

        if (source != destination)
        {
            if (graph[source - 1][destination - 1] == 0)
            {
                cout << "Enter weight of graph:- ";
                cin >> weight;
                graph[source - 1][destination - 1] = weight;
                cout << "Inserted edge of weight " << weight << " from " << source << " to " << destination << endl;
            }
            else
            {
                cout << "Edge already exists. Please select new edge" << endl;
                i--;
                continue;
            }
        }
        else
        {
            cout << "Source and destination cannot be the same" << endl;
            i--;
            continue;
        }
    }
    cout << "Graph created successfully!";
}

void Graph::display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            cout << setw(3) << graph[i][j];
        cout << endl;
    }
}

int Graph::findminvertex()
{
    int minvertex = -1;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
            minvertex = i;
    }
    return minvertex;
}

void Graph::dijkstras()
{
    for (int i = 0; i < vertices - 1; i++)
    {
        int minvertex = findminvertex();
        visited[minvertex] = true;
        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && graph[minvertex][j] != 0)
            {
                int dist = distance[minvertex] + graph[minvertex][j];
                if (dist < distance[j])
                    distance[j] = dist;
            }
        }
    }
    cout << "Vertex\tMinimum Distance" << endl;
    for (int i = 0; i < vertices; i++)
        cout << i + 1 << "\t  " << distance[i] << endl;
}

int main()
{
    Graph g;
    int choice, e, v;

    while (1)
    {

        cout << "\nImplementation of Dijkstra's algorithm" << endl;
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Find shortest path using Dijkstra's algorithm" << endl;
        cout << "4. Exit the program" << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the number of vertices:- ";
            cin >> v;
            cout << "\nEnter the number of edges:- ";
            cin >> e;
            g = Graph(v, e);
            g.create();
            break;

        case 2:
            g.display();
            break;

        case 3:
            g.dijkstras();
            break;

        case 4:
            return 0;

        default:
            cout << "\nError in choice, try again" << endl;
        }
    }
    return 0;
}

/* Output - 

tanmay@Predator:~/Code/DAA$ g++ 33259_dijkstras.cpp 
tanmay@Predator:~/Code/DAA$ ./a.out 

Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 1

Enter the number of vertices:- 5

Enter the number of edges:- 9
Enter the source vertex:- 1
Enter the destination vertex:- 2
Enter weight of graph:- 10
Inserted edge of weight 10 from 1 to 2
Enter the source vertex:- 1
Enter the destination vertex:- 5
Enter weight of graph:- 3
Inserted edge of weight 3 from 1 to 5
Enter the source vertex:- 2
Enter the destination vertex:- 3
Enter weight of graph:- 2
Inserted edge of weight 2 from 2 to 3
Enter the source vertex:- 2
Enter the destination vertex:- 5
Enter weight of graph:- 4
Inserted edge of weight 4 from 2 to 5
Enter the source vertex:- 3
Enter the destination vertex:- 4
Enter weight of graph:- 9
Inserted edge of weight 9 from 3 to 4
Enter the source vertex:- 4
Enter the destination vertex:- 3
Enter weight of graph:- 7
Inserted edge of weight 7 from 4 to 3
Enter the source vertex:- 5
Enter the destination vertex:- 2
Enter weight of graph:- 1
Inserted edge of weight 1 from 5 to 2
Enter the source vertex:- 5
Enter the destination vertex:- 4
Enter weight of graph:- 2
Inserted edge of weight 2 from 5 to 4
Enter the source vertex:- 5
Enter the destination vertex:- 3
Enter weight of graph:- 8
Inserted edge of weight 8 from 5 to 3
Graph created successfully!
Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 2
  0 10  0  0  3
  0  0  2  0  4
  0  0  0  9  0
  0  0  7  0  0
  0  1  8  2  0

Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 3
Vertex  Minimum Distance
1         0
2         4
3         6
4         5
5         3

Implementation of Dijkstra's algorithm
1. Create graph
2. Display graph
3. Find shortest path using Dijkstra's algorithm
4. Exit the program

Enter your choice:- 4

*/