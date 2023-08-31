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
    int vertices,operations;
    cin >> vertices >> operations;
    Graph graph(vertices);
    int i=0;
    while (i<operations){
        int x,y;
        char option;
        cin >> option;
        switch (option)
        {
        case 'I':
            cin >> x >> y;
            graph.insert_edge(Edge(x,y));
            break;
        case 'R':
            cin >> x >> y;
            graph.remove_edge(Edge(x,y));
            break;
        case 'E':
            cout << graph.get_Edges() << "\n";
            break;
        case 'N':
            cout << graph.get_vertices()<<"\n";
            break;
        case 'P':
            graph.print();
            break;
        case 'Q':
            //blabla
        default:
            break;
        }

        i++;
    }
    

    return 0;
}
