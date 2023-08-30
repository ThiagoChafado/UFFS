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
    
}
//Insert a Edge in the graph if is not in 
void Graph::insert_edge(Edge e){
    //checks if there is a loop
   if(e.v1 == e.v2){
        return;
   }
    for (std::list<int>::iterator i = adj_list_[e.v1].begin();i != adj_list_[e.v1].end();i++){
        //checks if not already in list
        if (*i == e.v2){
            return;
        }
    }
    adj_list_[e.v1].push_front(e.v2); 
    adj_list_[e.v2].push_front(e.v1);

}

void Graph::remove_edge(Edge e){
    
}

void Graph::print(){
    for(int i=0;i<num_vertices_;i++){
        cout << i << ":";
        for (std::list<int>::iterator j = adj_list_[i].begin();j != adj_list_[i].end();j++){
        cout << " "<< *j;
        }
        cout << "\n";
    }
}
