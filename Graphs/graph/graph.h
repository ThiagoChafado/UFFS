#ifndef GRAPH_H

#define GRAPH_H

#include <vector>
#include "aresta.h"

class Graph {
public:
/*Constroi um grafo simples que possui o numero de vertices recebido por parametro e que não possui arestas
*/
    Graph(int num_vertices_);
    
    int get_vertices();
    int get_aresta();

/*Insere uma aresta no grafo caso a aresta ainda não exista e não seja um laço*/
    void insert_aresta(Aresta e);

/*Remove uma aresta do grafo caso a aresta exista*/
    void remove_aresta(Aresta e);

    void print();

private:
    int  num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>>matriz_adj_;
};

#endif /* GRAPH_H */
