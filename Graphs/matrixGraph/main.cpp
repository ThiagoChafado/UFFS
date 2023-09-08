#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main(){
    try{
        
        Graph graph(7);
        vector<int> marked(7);
        marked.assign(7,0);


        graph.insert_edge(Edge (0,2));
        graph.insert_edge(Edge (0,4));
        //graph.insert_edge(Edge (1,2));
        graph.insert_edge(Edge (2,3));
        graph.insert_edge(Edge (2,4));
        graph.print();
        int v = graph.path(2,1,marked);
        graph.connected();
        cout << graph.acyclic() << "\n";
        

    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}