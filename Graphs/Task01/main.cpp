/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */

#include "Graph.h"

int main() {
    Graph graph(5);

    graph.insert_edge(Edge(1,3));
    graph.insert_edge(Edge(1,1));
    
    

    graph.print();
    
    

    return 0;
}
