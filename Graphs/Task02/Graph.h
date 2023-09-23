/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */


#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include "Edge.h"
#include <stack>
#include <queue>
#include <list>

class Graph {
public:
/*Constructs a simple graph that has the number of vertices received by parameter and that has no edges*/
    Graph(int num_vertices_);
    
    int get_vertices();
    int get_edge();

/*Inserts an edge into the graph if the edge does not yet exist and is not a loop*/
    void insert_edge(Edge e);

/*A breadth first search for a vertice,it returns a list of the possible companions*/
    std::list<int> breadthFirstSearch(int v, std::vector<int> &father, std::vector<int> &dist);

private:
    int num_vertices_;
    int num_edges_;
    std::vector<std::vector<int>>adj_matrix_;
};

#endif /* GRAPH_H */
