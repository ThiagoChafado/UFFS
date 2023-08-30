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

//Graph constructor
Graph::Graph(int num_vertices) {
    num_vertices_ = num_vertices;
    num_edges_ = 0;
    adj_list_.resize(num_vertices);
    for(int i = 0;i < num_vertices;i++){
        adj_list_[i].resize(num_vertices,0);
    }
}

void Graph::insert_edge(Edge e){
    
    
}

void Graph::remove_edge(Edge e){
    
}

void Graph::print(){
    for(int i=0;i<num_vertices_;i++){
        cout << i << ":";
        for(int j=0;j<num_vertices_;j++){
            ;
            
        }
        cout << "\n";
    }
}
