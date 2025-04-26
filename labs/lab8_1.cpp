#include <iostream>  
using namespace std; 

// Binary Search Tree (BST) 
// Left child < parent node < right child 

class node {
	// each node has two pointers: left and right
    int value;       // Value stored in the node
    node* left;      // Pointer to the left child
    node* right;     // Pointer to the right child
    friend class BST;
};

// Binary Search Tree class
class BST {
    node* root;         // Pointer to the root of the BST
	public:
	    BST() { root=NULL; };     // Constructor
	    void insert(int);         // Function to insert a new node
	    void print();             // Function to print the tree 
};

void BST::insert(int key) {
    // Create a new node and initialize its value and children
    node* n=new node;
    n->value=key;
    n->left=NULL;
    n->right=NULL; // first create as a leaf node

    node* parent=NULL;  // Pointer to track parent node while traversing

    if(root) // If tree is not empty
    {
        node* p=root;  // Start from the root node
        while(p) // continues until you reach a NULL position, which is the correct insertion point.
        {
        	// Set the root as the current parent
            parent=p;  
            if(key <= p->value)  // If key is less than or equal to current node
                p=p->left;       // Move to left subtree
            else
                p=p->right;      // Otherwise, move to right subtree
        };

        // Insert the new node as a child of the parent node
        if(key <= parent->value)
            parent->left=n; // If value is smaller than the parent, then insert to left
        else
            parent->right=n; // If value is bigger than the parent, then insert to right
    } else
        root=n; // Tree is empty, set root to new node
};

void BST::print() {
    cout <<"0)\t\t    " <<root->value <<endl; // Print root value

    // Print 1st level (children of root)
    cout <<"1)\t    " <<root->left->value <<"  \t\t    " <<root->right->value <<endl;

    // Print 2nd level (children of root's left and right children)
    cout <<"2)\t";
    
    // Print left-left child
    if(root->left->left)
        cout <<root->left->left->value <<"\t";
    else
        cout <<"-" <<"\t";

    // Print left-right child
    if(root->left->right)
        cout <<root->left->right->value <<"\t";
    else
        cout <<"-" <<"\t";

    // Print right-left child
    if(root->right->left)
        cout <<root->right->left->value <<"\t";
    else
        cout <<"-" <<"\t";

    // Print right-right child
    if(root->right->right)
        cout <<root->right->right->value <<endl;
    else
        cout <<"-" <<endl;
};

int main(){
	// Create a Binary Search Tree
    BST tree;  

    // Insert nodes into the BST
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    
    // Print the BST structure
    tree.print();
    
    cout <<endl <<endl;
    return 0;
};

