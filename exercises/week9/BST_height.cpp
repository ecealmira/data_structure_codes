#include <iostream>
#define C 8
using namespace std;

// BST Height Function

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
	    void print();
	    void print(node*, int);
	    void remove(int);
	    void remove(node* &, int);
	    
	    // height
	    int height();
	    int height(node* n);
};

void BST::insert(int key) {
    // Create the node
    node* n=new node;
    n->value=key;
    n->left=NULL;
    n->right=NULL;
    node* parent=NULL;  // need to find the parent
    if(root) {
        // Find the parent
        node* p=root;
        while(p) {
            parent=p;
            if(key <= p->value)
                p=p->left;
            else
                p=p->right;
        };
        // Insert as child of parent
        if(key <= parent->value)
            parent->left=n;
        else
            parent->right=n;
    } else
        root=n;
};

void BST::print(node* p, int space) {
    if (p) {
        space += C;
        print(p->right, space);
        cout << endl;
        for (int i = C; i < space; i++)  
            cout << " ";
        cout << p->value << endl;        
        print(p->left, space);
    } else
        return;
};


void BST::print()
{
    cout <<"------------------" <<endl;
    print(root, 1);
    cout <<endl <<"------------------" <<endl;
};

void BST::remove(int key)
{
    if(root) {
        cout <<"Removing the node with value " <<key <<":" <<endl;
        remove(root, key);
    } else
        cout <<"No node to remove as the tree is empty." <<endl;
};

void BST::remove(node* &n, int key){ // node passed by reference 
    if(key<(n->value)) {
        if(n->left)
            remove(n->left, key);
        else
            cout <<key <<" cannot be removed as it is not in the tree." <<endl;
    } else if(key>(n->value)) {
        if(n->right)
            remove(n->right, key);
        else
            cout <<key <<" cannot be removed as it is not in the tree." <<endl;
    } else {
        if((n->left)==NULL && (n->right)==NULL)
        { // No left and no right = Leaf
            delete n;
            n=NULL;
        }
        else if(n->left && n->right)
        { // Has left and right = 2 children
            node* m=n->left;
            while(m->right)
                m=m->right;
            n->value=m->value;
            remove(n->left, m->value);
        }
        else
        { // If one left or right = 1 child
            node* child = (n->left) ? (n->left) : (n->right);
            node* m=n; // copy n to m
            n=child; // copy child to parent
            delete m; // delete n (parent)
        };
    };
};

int BST::height() {
    int h = height(root);    // Get the height
    cout << "Height of Tree: " << h << endl;
    return h;                // Return the height
}

int BST::height(node* n) {    
    if (n == NULL)
        return 0;             // Base case: empty node has height 0
    // Recursive case: height is 1 + max(left height, right height)
    int left_height = height(n->left);
    int right_height = height(n->right);

    return 1 + max(left_height, right_height);
}

int main()
{
    BST tree;
    int keys[]={4,2,6,1,3,5,7};
    for(int i=0; i<7; i++)
        tree.insert(keys[i]);
    tree.print();
    
    tree.height();
    
    return 0;
};
