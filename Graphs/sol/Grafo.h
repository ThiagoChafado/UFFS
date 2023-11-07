#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
public:
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas
     */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     * nao seja um laco
     */
    void insere_aresta(Aresta e);

    /** Remove uma aresta do grafo caso a aresta exista no grafo */
    void remove_aresta(Aresta e);

    int coloracao_minima(std::vector<int> &min_col_cor);
    int coloracao(std::vector<int> &perm_verts, std::vector<int> &cor);
    void imprime_coloracao(int num_cores, std::vector<int> &cor);

    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
