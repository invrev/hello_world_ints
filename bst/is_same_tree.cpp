#include<iostream>
struct bst {
    struct bst* left;
    struct bst* right;
    int val;
};
//compare tree by values and structure 

bool is_same_tree (bst* p, bst* q) {
  if (p && q) {
      //return (value_cmp && structure_cmp)
      return ( p->val == q->val 
              && (is_same_tree (p->left,q->left))
              && (is_same_tree (p->right,q->right)) );
  } else if (p != 0 || q != 0) {
      return false;
  }
}
