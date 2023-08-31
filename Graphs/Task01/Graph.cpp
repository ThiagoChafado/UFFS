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
   }//iterates over the list
    for (std::list<int>::iterator i = adj_list_[e.v1].begin();i != adj_list_[e.v1].end();i++){
        //checks if not already in list using pointer to the element of i
        if (*i == e.v2){
            return;
        }
    }
    adj_list_[e.v1].push_front(e.v2); 
    adj_list_[e.v2].push_front(e.v1);
    num_edges_++;

}

void Graph::remove_edge(Edge e){
    int flag = 0;
    for(std::list<int>::iterator i = adj_list_[e.v1].begin();i != adj_list_[e.v1].end();i++){
        //checking if exists
        if(*i == e.v2){
            //whithout a flag, i got segmentation error,don't know why
            flag = 1;
        }
    }
    if (flag ==1 ){
        //removes
        adj_list_[e.v1].remove(e.v2);
        adj_list_[e.v2].remove(e.v1);
        num_edges_--;
    }
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
