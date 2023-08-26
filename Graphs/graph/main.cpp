#include "graph.h"
#include "aresta.h"
#include <iostream>

using namespace std;

int main(){
    try{
        Graph graph(5);

        graph.print();

        Aresta e(3,4);
        graph.insert_aresta(e);
        graph.insert_aresta(Aresta(4,2));
        graph.print();
    }catch (const exception &e){
        cerr << "exception: " << e.what() << "\n";
    }
return 0;
}