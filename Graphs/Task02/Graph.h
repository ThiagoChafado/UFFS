#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include "Edge.h"
#include <stack>
#include <queue>

class Graph {
public:
/*Constructs a simple graph that has the number of vertices received by parameter and that has no edges*/
    Graph(int num_vertices_);
    
    int get_vertices();
    int get_edge();

/*Inserts an edge into the graph if the edge does not yet exist and is not a loop*/
    void insert_edge(Edge e);

/*Removes an edge from the graph if the edge exists*/
    void remove_edge(Edge e);

/*Prints a graph*/
    void print();

    void breadthFirstSearch(int v, int father[], int dist[]);

private:
    int num_vertices_;
    int num_edges_;
    std::vector<std::vector<int>>adj_matrix_;
};

#endif /* GRAPH_H */
