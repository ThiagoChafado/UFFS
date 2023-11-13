/*
 * Tarefa 04 - Desbravo Bros
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */


#include "Digraph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main(){
    try{
        int r,c;
        cin >> r >> c;
        Digraph digraph(r);
        int i=0;
        
        while(i<c){
            int x,y,d;
            cin >> x >> y >> d;
            digraph.insert_edge(Edge(x,y,d));
            i++;
        }
        
        
        

    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}