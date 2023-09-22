#include "Graph.h"
#include <iostream>

using namespace std;

int Graph::get_vertices()
{
    return num_vertices_;
}
int Graph::get_edge()
{
    return num_edges_;
}

Graph::Graph(int num_vertices)
{
    num_vertices_ = num_vertices;
    num_edges_ = 0;
    adj_matrix_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        adj_matrix_[i].resize(num_vertices, 0);
    }
}

void Graph::insert_edge(Edge e)
{
    if (adj_matrix_[e.v1][e.v2] == 0 && (e.v1 != e.v2))
    {
        adj_matrix_[e.v1][e.v2] = 1;
        adj_matrix_[e.v2][e.v1] = 1;
        num_edges_++;
    }
}

void Graph::print()
{
    for (int i = 0; i < num_vertices_; i++)
    {
        cout << i << ":";
        for (int j = 0; j < num_vertices_; j++)
        {
            if (adj_matrix_[i][j] != 0)
            {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
}

void Graph::breadthFirstSearch(int v, vector<int> &father, vector<int> &dist)
{
    vector<int> marked(num_vertices_);
    marked.assign(num_vertices_, 0);
    queue<int> queue;
    marked[v] =1;
    father[v] = -1;
    dist[v] = 0;
    queue.push(v);
    while (!queue.empty())
    {
        int w = queue.front();
        queue.pop();
        printf("%d\n", w);
        for (int u = 0; u < num_vertices_; u++)
            if (adj_matrix_[w][u] != 0)
                if (marked[u] == 0)
                {
                    marked[u] =1;
                    father[u] = w;
                    dist[u] = dist[w] + 1;
                    queue.push(u);
                }
    }
}