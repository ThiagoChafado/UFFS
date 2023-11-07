#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices)
{
    if (num_vertices <= 0)
    {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
                               "vertices " +
                               to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    { // ou i < matriz_adj_.size()
      // Esta observacao tambem vale
      // para lacos semelhantes neste
      // arquivo
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices()
{
    return num_vertices_;
}

int Grafo::num_arestas()
{
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e)
{
    try
    {
        valida_aresta(e);
    }
    catch (...)
    {
        throw_with_nested(runtime_error("Erro na operacao "
                                        "insere_aresta(Aresta): a aresta " +
                                        e.to_string() + " eh "
                                                        "invalida!"));
    }

    if ((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2))
    {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e)
{
    try
    {
        valida_aresta(e);
    }
    catch (...)
    {
        throw_with_nested(runtime_error("Erro na operacao "
                                        "remove_aresta(Aresta): a aresta " +
                                        e.to_string() + " eh "
                                                        "invalida!"));
    }

    if (matriz_adj_[e.v1][e.v2] != 0)
    {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

int Grafo::coloracao_minima(vector<int> &min_col_cor)
{
    vector<int> perm_verts(num_vertices_);
    for (int i = 0; i < num_vertices_; i++)
    {
        perm_verts[i] = i;
    }

    int min_col_num_cores = numeric_limits<int>::max();

    int num_cores;
    vector<int> cor(num_vertices_);

    do
    {
        num_cores = coloracao(perm_verts, cor);
        if (num_cores < min_col_num_cores)
        {
            min_col_num_cores = num_cores;
            min_col_cor = cor;
        }
    } while (next_permutation(perm_verts.begin(), perm_verts.end()));

    return min_col_num_cores;
}

int Grafo::coloracao(vector<int> &perm_verts, vector<int> &cor)
{

    fill(cor.begin(), cor.end(), 0);
    for (int i = 0; i < perm_verts.size(); i++)
    {
        vector<int> neighbor_colors(perm_verts.size());
        fill(neighbor_colors.begin(), neighbor_colors.end(), 0);

        for (int j = 0; j < perm_verts.size(); j++)
        {
            if (matriz_adj_[perm_verts[i]][j] == 1)
            {
                if (cor[j] != 0)
                {
                    neighbor_colors.push_back(cor[j]);
                }
            }
        }
        int color = 0;
        while (cor[perm_verts[i]] == 0)
        {
            color++;
            int found = 0;
            for (int j = 0; j < neighbor_colors.size(); j++)
            {
                if (neighbor_colors[j] == color)
                {
                    found = 1;
                }
                
            }
            if (found == 0)
                {
                    cor[perm_verts[i]] = color;
                }
        }
    }
    vector<int> check = cor;
    sort(check.begin(), check.end(), greater<int>());
    return check[0];
}

void Grafo::imprime_coloracao(int num_cores, vector<int> &cor)
{
    cout << "Numero de cores: " << num_cores << "\n";
    for (int i = 1; i <= num_cores; i++)
    {
        cout << "Cor " << i << ":";
        for (int v = 0; v < num_vertices_; v++)
        {
            if (cor[v] == i)
            {
                cout << " " << v;
            }
        }
        cout << "\n";
    }
}

void Grafo::imprime()
{
    for (int v = 0; v < num_vertices_; v++)
    {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++)
        {
            if (matriz_adj_[v][u] != 0)
            {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}

void Grafo::valida_vertice(int v)
{
    if ((v < 0) || (v >= num_vertices_))
    {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e)
{
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}
