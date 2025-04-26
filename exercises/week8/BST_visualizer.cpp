#include <iostream>  
using namespace std; 

// Binary Search Tree (BST) Visualizer
// Left child < parent node < right child 

class node {
    int value;       
    node* left;      
    node* right;     
    friend class BST;
};

class BST {
    node* root;         
	public:
	    BST() { root=NULL; };     
	    void insert(int);         
	    void print();             // Public print function
	private:
	    void print(node *n, int space);  // Internal recursive function
};

// Function to insert a new node into the BST
void BST::insert(int key) {
    node* n = new node;
    n->value = key;
    n->left = NULL;
    n->right = NULL; 

    node* parent = NULL;  

    if(root) {
        node* p = root;  
        while(p) {
            parent = p;  
            if(key <= p->value)
                p = p->left;
            else
                p = p->right;
        }

        if(key <= parent->value)
            parent->left = n;
        else
            parent->right = n;
    } else {
        root = n;
    }
}

// Recursive helper function to print the tree in rotated 2D
void BST::print(node *n, int space) {
	if(n == NULL) {
		return;
	}
	
	space += 3;

	// Process right child first
	print(n->right, space);
	cout << endl;

	// Print current node after space count
	for (int i = 3; i < space; i++) {
		cout << " ";
	}
	cout << n->value << "\n";

	// Process left child
	print(n->left, space);
}

// Public print wrapper that starts from the root
void BST::print() {
	print(root, 0);
}

int main(){
    BST tree;  

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    
    tree.print();  // Correctly call the print function with no arguments

    cout << endl << endl;
    return 0;
}

