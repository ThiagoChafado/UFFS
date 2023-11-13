/*
 * Tarefa 04 - Desbravo Bros
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */


#ifndef DIGRAPH_H

#define DIGRAPH_H

#include <vector>
#include "Edge.h"
#include <stack>
#include <queue>
#include <list>

class Digraph {
public:
/*Constructs a simple digraph that has the number of vertices received by parameter and that has no edges*/
    Digraph(int num_vertices_);
    
    int get_vertices();
    int get_edge();

/*Inserts an edge into the digraph if the edge does not yet exist and is not a loop*/
    void insert_edge(Edge e);

    int max_lifes(int v);

private:
    int num_vertices_;
    int num_edges_;
    std::vector<std::vector<int>>adj_matrix_;
};

#endif /* DIGRAPH_H */
