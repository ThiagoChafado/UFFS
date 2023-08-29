#include "graph.h"
#include <iostream>

using namespace std;

int Graph::get_vertices(){
    return num_vertices_;
}
int Graph::get_aresta(){
    return num_arestas_;
}

Graph::Graph(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for(int i = 0;i < num_vertices;i++){
        matriz_adj_[i].resize(num_vertices,0);
    }
}

void Graph::insert_aresta(Aresta e){
    if(matriz_adj_[e.v1][e.v2] == 0 && (e.v1 != e.v2)){
        matriz_adj_[e.v1][e.v2] = 1;
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
