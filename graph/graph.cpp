#include<iostream>
#include<vector>
using namespace std;

//struct is just graphNode
struct edgeNode {
    int label;
    int wt;
    vector<edgeNode *> edge_list;
    edgeNode (int a_label,int a_wt) : 
        wt (a_wt) , label (a_label)
    {

    };

};



struct graph {
    bool is_directed;
    int no_of_vertex;
    int no_of_edges;
    vector<edgeNode*> adj_list;
    graph (bool a_is_directed,int a_no_of_vertex,int a_no_of_edges) :
        is_directed(a_is_directed),no_of_vertex (a_no_of_vertex), no_of_edges(a_no_of_edges)
    {

    };
};

void insert_edge (graph &g,int x,int y) {
    
    edgeNode *e = new edgeNode(y,0);

    if (g.adj_list.size() == 0) {
        g.adj_list.push_back (e);
    } else {
        //find the list
    }
}


int main () {
    int label0[] = {1,3,8,13,9};
    int label1[] = {2,10,5};
    int label2[] = {6};
    int label3[] = {7,12,16};
    int label4[] = {17};
    int label5[] = {7,12,16};
    //graph* g = new graph (false,10,10);
    graph g(false,10,10);

    //insert edge (1,2)
    insert_edge (g,1,2);
    
}




