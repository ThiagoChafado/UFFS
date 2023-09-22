#include "Graph.h"
#include "Edge.h"
#include <iostream>

using namespace std;

int main(){
    try{
        
        Graph graph(6);
        vector<int> marked(6);
        marked.assign(6,0);
        vector<int> father(6);
        vector<int> dist(6);
        graph.insert_edge(Edge(2,5));
        graph.insert_edge(Edge(0,4));
        graph.insert_edge(Edge(3,5));
        graph.insert_edge(Edge(1,3));
        graph.insert_edge(Edge(0,5));
        graph.insert_edge(Edge(2,4));
        graph.breadthFirstSearch(4,father,dist);


        
        
        
        

    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}