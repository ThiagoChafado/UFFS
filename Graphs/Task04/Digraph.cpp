/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */


#include "Digraph.h"
#include <iostream>

using namespace std;

int Digraph::get_vertices()
{
    return num_vertices_;
}
int Digraph::get_edge()
{
    return num_edges_;
}

Digraph::Digraph(int num_vertices)
{
    num_vertices_ = num_vertices;
    num_edges_ = 0;
    adj_matrix_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        //Set 2147483647 for the initial edge(same as no edge)
        adj_matrix_[i].resize(num_vertices, __INT_MAX__);
    }
}

void Digraph::insert_edge(Edge e)
{
    if (adj_matrix_[e.v1][e.v2] == __INT_MAX__ && (e.v1 != e.v2))
    {
        adj_matrix_[e.v1][e.v2] = e.weight;
        num_edges_++;
    }
}

