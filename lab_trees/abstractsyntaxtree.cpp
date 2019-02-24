#include "abstractsyntaxtree.h"

using namespace std;
/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...
    Node* root=getRoot();
    return eval(root);
}


double AbstractSyntaxTree::eval(Node* root) const {
// if (root==NULL) return 0;
// int lheight=height(root->left);
// int rheight=height(root->right);
// int ldiameter=diameter(root->left);
// int rdiameter=diameter(root->right);
//
// return max(lheight+rheight+1; max(ldiameter,rdiameter));
if(!root) return 0;
if(!root->left && !root->right) return stod(root->elem);

double l_val=eval(root->left);

double r_val=eval(root->right);

if(root->elem=="+") return l_val+r_val;
if(root->elem=="-") return l_val-r_val;
if(root->elem=="*") return l_val*r_val;
//if(root->elem=="/") 
return l_val/r_val;

}
