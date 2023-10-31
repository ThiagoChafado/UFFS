#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {

        Graph graph(10);
        vector<int> marked(10);
        marked.assign(10, 0);
        int v = graph.get_vertices();

        graph.insert_edge(Edge(0, 2));
        graph.insert_edge(Edge(0, 9));
        graph.insert_edge(Edge(1, 3));
        graph.insert_edge(Edge(2, 3));
        graph.insert_edge(Edge(2, 4));
        graph.insert_edge(Edge(2, 5));
        graph.insert_edge(Edge(2, 7));
        graph.insert_edge(Edge(3, 4));
        graph.insert_edge(Edge(3, 5));
        graph.insert_edge(Edge(3, 6));
        graph.insert_edge(Edge(3, 7));
        graph.insert_edge(Edge(3, 8));
        graph.insert_edge(Edge(5, 9));
        graph.insert_edge(Edge(7, 8));   
        graph.insert_edge(Edge(7, 9));     
        // graph.print();
        // int v = graph.path(2,1,marked);
        //(graph.connected() ) ? cout << "YES\n" : cout << "NO\n";
        //(graph.acyclic()) ? cout << "YES\n" : cout << "NO\n";
        //  graph.deepFirstSearch(0,marked);

        int flag;

        for (int j = 0; j < v; j++)
        {
            if (!graph.parity(j))
            {
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }

        (flag == 1) ? cout << "Yes\n" : cout << "No\n";
    }
    catch (const exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
    }
    return 0;
}