/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Thiago Chafado Almeida
 * Matricula: 2211100023
 */


#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main(){
    try{
        int person,call;
        cin >> person >> call;
        Graph graph(person);
        int i =0;
        while(i<call){
            int x,y;
            char time;
            cin >> x >> y >> time;
            if (time == 'W'){
                graph.insert_edge(Edge(x,y));
            }
            i++;
        }
        int timesSearch;
        cin >> timesSearch;
        i=0;
        vector<int> father(person);
        vector<int> dist(person);
        while (i<timesSearch){
            int bfs;
            cin >> bfs;
            list<int> companions;
            companions = graph.breadthFirstSearch(bfs,father,dist);
            //sort the linked list
            companions.sort();

            cout << bfs << ':';
            for(auto i: companions){
                cout << i << ' ';
        }
        cout << "\n";
        i++;


        }
        
        
        

    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}