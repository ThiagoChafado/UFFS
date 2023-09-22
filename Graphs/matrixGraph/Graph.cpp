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

void Graph::remove_edge(Edge e)
{
    if (adj_matrix_[e.v1][e.v2] == 1)
    {
        adj_matrix_[e.v1][e.v2] = 0;
        adj_matrix_[e.v2][e.v1] = 0;
        num_edges_--;
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
bool Graph::path(int v, int w, vector<int> marked)
{
    if (v == w)
    {
        // printf("%d-", v);
        return true;
    }
    marked[v] = 1;
    for (int u = 0; u < num_vertices_; u++)
        if (adj_matrix_[v][u] != 0)
            if (marked[u] == 0)
                if (path(u, w, marked))
                {
                    // printf("%d-", v);
                    return true;
                }
    return false;
}

bool Graph::connected()
{

    vector<int> marked(num_vertices_);
    marked.assign(num_vertices_, 0);
    deepFirstSearch(0, marked);
    int acumulator = 0;

    for (int j = 0; j < num_vertices_; j++)
    {
        if (marked[j] == 1)
        {
            acumulator++;
        }
    }
    if (acumulator == num_vertices_)
    {
        return true;
    }
    return false;
}

int Graph::acyclic()
{
    int answer = 1;
    for (int i = 0; i < num_vertices_; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (adj_matrix_[i][j] == 1)
            {
                remove_edge(Edge(i, j));
                vector<int> marked(num_vertices_);
                marked.assign(num_vertices_, 0);
                if (path(i, j, marked))
                {
                    answer = 0;
                }
                insert_edge(Edge(i, j));
            }
        }
    }
    return answer;
}

void Graph::deepFirstSearch(int v, vector<int> &marked)
{
    // printf("%d\n", v);
    marked[v] = 1;
    for (int u = 0; u < num_vertices_; u++)
        if (adj_matrix_[v][u] != 0)
            if (marked[u] == 0)
                deepFirstSearch(u, marked);
}

void Graph::dfsWithStack(int v)
{
    vector<int> marked(num_vertices_);
    marked.assign(num_vertices_, 0);
    stack<int> stack;
    stack.push(v);
    while (!stack.empty())
    {
        int w = stack.top();
        stack.pop();
        if (marked[w] == 0)
        {
            printf("%d\n", w);
            marked[w] = 1;
            for (int u = (num_vertices_ - 1); u >= 0; u--)
                if (adj_matrix_[w][u] != 0)
                    if (marked[u] == 0)
                        stack.push(u);
        }
    }
}
