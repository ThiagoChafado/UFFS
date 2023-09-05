#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main(){
    try{
        
        Graph graph(4);
        vector<int> marked(4);
        marked.assign(5,0);


        graph.insert_edge(Edge (0,1));
        graph.insert_edge(Edge (0,2));
        graph.insert_edge(Edge (1,2));
        graph.insert_edge(Edge (1,3));
        graph.insert_edge(Edge (2,3));
        graph.print();
        int v = graph.path(2,1,marked);
        graph.connected();

    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}