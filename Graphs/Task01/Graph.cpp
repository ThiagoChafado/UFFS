/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */

#include "Graph.h"
#include <iostream>

using namespace std;

int Graph::get_vertices(){
    return num_vertices_;
}
int Graph::get_Edges(){
    return num_edges_;
}

Graph::Graph(int num_vertices) {
    num_vertices_ = num_vertices;
    num_edges_ = 0;
    list.adj_.resize(num_vertices);
    for(int i = 0;i < num_vertices;i++){
        list.adj_[i].resize(num_vertices,0);
    }
}

void Graph::insert_edge(Aresta e){
    if(list.adj_[e.v1][e.v2] == 0 && (e.v1 != e.v2)){
        list.adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;
        num_arestas_++;
    }
    
}

void Graph::remove_aresta(Aresta e){
    if(matriz_adj_[e.v1][e.v2] == 1){
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;
        num_arestas_--;
    }
}

void Graph::print(){
    for(int i=0;i<num_vertices_;i++){
        cout << i << ":";
        for(int j=0;j<num_vertices_;j++){
            if(matriz_adj_[i][j] != 0){
                cout << " " <<j;
            }
        }
        cout << "\n";
    }
}
