#include <iostream>
#include "graph.h"

using namespace std;

int main(){
    Graph gmap;
    gmap.addVertex(7);
    gmap.addVertex(10);
    gmap.addVertex(8);
    gmap.addVertex(12);
    gmap.addEdges(7,8);
    gmap.addEdges(7,10);
    gmap.addEdges(12,8);
    gmap.addEdges(8,10);
    gmap.addEdges(10,12);
    gmap.showEdges();
    return 0;
}