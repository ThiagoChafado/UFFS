#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include "aresta.h"

class Graph {
public:
    Graph(int num_vertices_);
    
    int get_vertices();
    int get_aresta();

    void insert_aresta(Aresta e);
    void remove_aresta(Aresta e);

    void print();

private:
    int  num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>>matriz_adj_;
};

#endif /* GRAPH_H */
