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
            //inserts the edge with the value * -1
            digraph.insert_edge(Edge(x,y,d*-1));
            i++;
        }
        int executions;
        cin >> executions;
        i=0;
        while(i<executions){
            vector<int> father(digraph.get_vertices());
            father.assign(digraph.get_vertices(), 0);
            vector<int> dp(digraph.get_vertices());
            dp.assign(digraph.get_vertices(), 0);
            int vertex;
            cin >> vertex;
            bool verify = digraph.bellmanFord(vertex,father,dp);
            if (verify == false){
                cout << vertex <<":" <<" ilimitada\n";
            }else{
                int max = digraph.maxLife(vertex);
                cout << vertex << ": " << max << "\n";
            }
            i++;
        }
        
        
        

    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}