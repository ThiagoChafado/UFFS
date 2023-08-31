/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */
#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph graph(5);

    graph.insert_edge(Edge(1,3));
    graph.insert_edge(Edge(1,1));
    graph.insert_edge(Edge(1,4));
    graph.remove_edge(Edge(1,3));
    

    
    

    graph.print();

    cout << "Vertices:" << graph.get_vertices() << "\n";
    cout << "Edges:" << graph.get_Edges() << "\n";
    
    

    return 0;
}
