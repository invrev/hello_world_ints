#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct UndirectedGraphNode  {
    int label;
    vector<UndirectedGraphNode* > neighbors;
    UndirectedGraphNode (int x) : label(x) {};
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {

    if (node == NULL) {
        return node;
    }

    stack<UndirectedGraphNode* > explore_stack;
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode* > visited_map;
    unordered_set<int> explorer_set;
    explore_stack.push(node);
    while (!explore_stack.empty()) {
        UndirectedGraphNode* tmpNode = explore_stack.top();
        explore_stack.pop();
        //Maintain visited labels
        if (explorer_set.find(tmpNode->label) == explorer_set.end() ) {
            explorer_set.insert(tmpNode->label);
            //copy node
            if (visited_map.find(tmpNode) == visited_map.end() ) {
                visited_map[tmpNode] = new UndirectedGraphNode(tmpNode->label);
            }

            //copy neighbors
            for (auto p : tmpNode->neighbors ) {
                if (visited_map.find(p) == visited_map.end() ) {
                    visited_map[p] = new UndirectedGraphNode(p->label);
                } 
                visited_map[tmpNode]->neighbors.push_back(visited_map[p]);
                if (explorer_set.find(p->label) == explorer_set.end() ) {
                    explore_stack.push(p);
                }
            }
        }
    }

    return visited_map[node];
}

int main () {

}
