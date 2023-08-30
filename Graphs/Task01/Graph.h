/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida    
 * Matricula: 2211100023
 */

#ifndef GRAPH_H

#define GRAPH_H

#include "Edge.h"

class Graph {
public:
    Graph(int num_vertices);
    // ~Graph(); // Se necessario
    int get_vertices();
    int get_Edges();
    void insert_Edge(Edge e);
    void remove_Edge(Edge e);
    void remove_vertex(int v);
    void print();
private:
    int num_vertices_;
    int num_edges_;
};

#endif /* GRAPH_H */
