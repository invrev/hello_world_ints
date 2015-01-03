#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>
#include<limits.h>
using namespace std;


//Check wheather graph is bipartite or not by coloring with BFS
bool graphBiColoring (unordered_map<int,vector<int>>& graph,int initVertex) {

    //queue< pair<int,char> > vColorq; 
    int totalVertex = graph.size();
    //Used to visit the graph
    queue<int> visitedQ;
    vector<int> vColor(totalVertex,-1);
    visitedQ.push(initVertex);
    int color = 0;
    //Store the color
    vColor[initVertex] = color;
    while (!visitedQ.empty() ) {
        int v = visitedQ.front();
        //change color
        color = (color + 1) % 2;
        for (int i = 0; i < graph[v].size(); i++ ) {
            int tmpV = graph[v][i];
            if (vColor[tmpV] == -1 || vColor[tmpV] != color ) {
                visitedQ.push(tmpV);
                vColor[tmpV] = color;
            } else {
                return false;
            }
        }
        visitedQ.pop();
    }
    return true;
}


bool graphColorDFS (unordered_map<int,vector<int>>& graph,vector<int> &vColor,int initV,char color) {
    
    int n = graph[initV].size() ;
    for (int i=0;i<n;i++) {
        if (vColor[graph[initV][i]] == -1) {
            vColor[graph[initV][i]] = color;
            if (graphColorDFS (graph,vColor,i,!color) == false) {
                return false;
            }
        } else {
            if (vColor[graph[initV][i]] == color) {
                return false;
            }
        }
    }

}




int main () {

    unordered_map<int,vector<int> > graph;
    int initV = 1;
    graphBiColoring (graph,initV);
}
