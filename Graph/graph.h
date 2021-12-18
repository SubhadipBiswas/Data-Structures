#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph{
private:
    map<int, vector<int>>vertices;
    int totalNodes;
public:
    Graph();
    void addVertex(int node);
    void addEdges(int node1, int node2);
    void showEdges();
};

Graph::Graph(){
    totalNodes = 0;
}

void Graph::addVertex(int node){
    if(totalNodes == 0){
        vector<int>edges;
        vertices.insert(vertices.begin(),pair<int, vector<int>>(node,edges));
        totalNodes++;
    }
    else{
        vector<int>edges;
        vertices.insert(pair<int, vector<int>>(node,edges));
        totalNodes++;
    }
}

void Graph::addEdges(int node1,int node2){
    vertices[node1].push_back(node2);
}

void Graph::showEdges(){
    map<int, vector<int>>::iterator vtx;
    for(vtx = vertices.begin(); vtx!=vertices.end(); ++vtx){
        cout<<vtx->first<<"->";
        for(int edg = 0;edg<vtx->second.size();edg++){
            cout<<vtx->second[edg]<<",";
        }
    }
    cout<<endl;
}