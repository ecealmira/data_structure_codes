#include <iostream>
#include <cmath>
#define C 8
using namespace std;

// BST Height & Balanced

class node
{
    int value;
    node* left; // left child
    node* right; // right child
	friend class BST;
};

class BST
{
    node* root;
  	public:
	    BST() { root=NULL; };
	    void insert(int);
	    void print();
	    void print(node*, int);
	    int height();
	    int height(node*);
	    bool balanced();
	    bool balanced(node*);
};

void BST::insert(int key)
{
    // Create the node
    node* n=new node;
    n->value=key;
    n->left=NULL;
    n->right=NULL;
    node* parent=NULL;  // need to find the parent
    if(root)
    {
        // Find the parent
        node* p=root;
        while(p)
        {
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
    }
    else
        root=n;
};

void BST::print(node* p, int space)
{
    if(p)
    {
        space+=C;
        print(p->right, space);
        cout <<endl;
        for(int i=C; i<space; i++)
            cout<<" ";
        cout <<p->value <<endl;
        print(p->left, space);
    }
    else
        return;
};

void BST::print()
{
    cout <<"------------------" <<endl;
    print(root, 1);
    cout <<endl <<"------------------" <<endl;
};

int BST::height(node* n)
{
    if(n) // find the height of every subtree
        return 1 + max( height(n->left) , height(n->right) );
    else
        return -1;
};

int BST::height()
{
    int h=height(root);
    cout <<"Height of the tree: " <<h <<endl;
    return h;
};

bool BST::balanced(node* n)
{
    if(n)
    {
        int lh=height(n->left);
        int rh=height(n->right);
        // if height difference between left and right is smaller or equal to 1, 
		// then return true
        if( abs(lh-rh)<=1 && balanced(n->left) && balanced(n->right) )
            return 1;
        else
            return 0;
    }
    else
        return 1; // no nodes, balanced
};

bool BST::balanced()
{
    if(balanced(root))
    {
        cout <<"Tree is balanced." <<endl;
        return 1;
    }
    else
    {
        cout <<"Tree is not balanced." <<endl;
        return 0;
    };
};


int main()
{
    BST tree;
    
    // create the tree
    int keys[]={4,2,1,6,3,5,7};
    for(int i=0; i<7; i++)
        tree.insert(keys[i]);
        
    // print the tree
    tree.print();
    
    // height
    tree.height();
    
    // balance
    tree.balanced();

    cout <<endl <<endl;
    return 0;
};
