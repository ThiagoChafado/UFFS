#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {
        int V;
        int E;
        int v1;
        int v2;

        cin >> V >> E;

        Grafo g(V);

        for (int i = 0; i < E; i++) {
            cin >> v1 >> v2;
            g.insere_aresta(Aresta(v1, v2));
        }

        vector<int> min_col_cor(V);

        int min_col_num_cores = g.coloracao_minima(min_col_cor);
        g.imprime_coloracao(min_col_num_cores, min_col_cor);
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
