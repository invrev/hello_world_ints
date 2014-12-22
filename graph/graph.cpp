#include<iostream>
#include<vector>
using namespace std;

//Representaion of graph with adjacency list
//struct is just Edgenode 
struct EdgeNode {
    int label;
    int wt;
    EdgeNode *next; 
    EdgeNode (int a_label,int a_wt) : 
        wt (a_wt) , label (a_label),next(NULL)
    {
    };

};

struct Graph {
    bool is_directed;
    int no_of_vertex;
    int no_of_edges;
    //Vertex indexed array
    vector<EdgeNode*> adj_list;
    Graph (bool a_is_directed,int a_no_of_vertex,int a_no_of_edges) :
        is_directed(a_is_directed),no_of_vertex (a_no_of_vertex), no_of_edges(a_no_of_edges),adj_list(no_of_vertex)
    {

    };
};

void insert_edge (Graph &g,int src,int dest) {
    
    EdgeNode *e = new EdgeNode(dest,0);
    e->next = g.adj_list[src];
    g.adj_list[src] = e;
}

void printGraph(Graph &g) {
    for (int i=0;i<g.no_of_vertex;i++) {
        EdgeNode *e = g.adj_list[i];
        cout << "Vetrex V = " << i << endl;
        while (e != NULL) {
            cout << "(" << e->label << "," << e->wt << ")";
            e = e->next;
        }
        cout << endl;
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
    Graph g(false,6,16);

    //Insert edges
    for (int i=0;i<sizeof(label0)/sizeof(label0[0]);i++) {
        insert_edge (g,0,label0[i]);
    }

    for (int i=0;i<sizeof(label1)/sizeof(label1[0]);i++) {
        insert_edge (g,1,label1[i]);
    }

    for (int i=0;i<sizeof(label2)/sizeof(label2[0]);i++) {
        insert_edge (g,2,label2[i]);
    }

    for (int i=0;i<sizeof(label3)/sizeof(label3[0]);i++) {
        insert_edge (g,3,label3[i]);
    }

    for (int i=0;i<sizeof(label4)/sizeof(label4[0]);i++) {
        insert_edge (g,4,label4[i]);
    }

    for (int i=0;i<sizeof(label5)/sizeof(label5[0]);i++) {
        insert_edge (g,5,label5[i]);
    }
    printGraph (g);
    
    //EdgeNode *n = new EdgeNode(1,1);
    //n->next = g.adj_list[0];
    //g.adj_list[0] = n;

    //insert edge (1,2)
    //insert_edge (g,1,2);
   


   //Add into linked list 
   //3->null 2->null

}




