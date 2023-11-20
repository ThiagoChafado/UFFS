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
        // Set 2147483647 for the initial edge(same as no edge)
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

int Digraph::maxLife(int v)
{
    int count = 0;
    int maxLife = 0;
    vector<int> marked(num_vertices_);
    marked.assign(num_vertices_, 0);
    queue<int> queue;
    marked[v] = 1;
    queue.push(v);
    while (!queue.empty())
    {   
        int w = queue.front();
        queue.pop();

        for (int u = 0; u < num_vertices_; u++)
        {
            
            if (adj_matrix_[w][u] != __INT_MAX__)
                if (marked[u] == 0)
                {
                    marked[u] = 1;
                    count = count + adj_matrix_[w][u];
                    if (count <= maxLife)
                    {
                        maxLife = count;
                    }
                    queue.push(u);
                }
        }
    }
    return maxLife * -1;
}

bool Digraph::bellmanFord(int s,vector<int> &father,vector<int> &dp){
    for(int w=0;w<num_vertices_;w++){
        dp[w]=__INT_MAX__;
        father[w] = -1;
    }
    dp[s] = 0;
    //relax edge
    for(int i=1;i<=num_vertices_-1;i++){
        for(int u=0;u<num_vertices_;u++){
            for(int v=0;v<num_vertices_;v++){
                if(adj_matrix_[u][v] != __INT_MAX__){
                    if (dp[u] != __INT_MAX__ && dp[v] > dp[u] + adj_matrix_[u][v]){
                    dp[v] = dp[u] + adj_matrix_[u][v];
                    father[v] = u;
                    }
                }
                
            }
        }
    }
    //verify
    for(int i=0;i<num_vertices_;i++){
        for(int j=0;j<num_vertices_;j++){
            if(adj_matrix_[i][j] != __INT_MAX__){
                if(dp[i] != __INT_MAX__ && dp[j] > dp[i] + adj_matrix_[i][j]){
                    return false;
                }  
            }
        }
    }
    return true;
}