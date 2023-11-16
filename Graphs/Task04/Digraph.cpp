/*
 * Tarefa 04 - Desbravo Bros
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

int Digraph::breadthFirstSearch(int v, vector<int> &father, vector<int> &dist)
{
    int count = 0;
    int maxLife = 0;
    vector<int> marked(num_vertices_);
    marked.assign(num_vertices_, 0);
    queue<int> queue;
    marked[v] = 1;
    father[v] = __INT_MAX__;
    dist[v] = 0;
    queue.push(v);
    while (!queue.empty())
    {
        int w = queue.front();
        queue.pop();
        
        for (int u = 0; u < num_vertices_; u++)
            if (adj_matrix_[w][u] != __INT_MAX__)
                if (marked[u] == 0)
                {
                    marked[u] = 1;
                    father[u] = w;
                    dist[u] = dist[w] + 1;
                    count = count + adj_matrix_[w][u];
                    if (count <= maxLife){
                        maxLife = count;
                    }
                    queue.push(u);
                }

    }
    return maxLife * -1;
}
