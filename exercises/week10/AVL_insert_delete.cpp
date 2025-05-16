#include <iostream>
#include <cmath>
#define C 8
using namespace std;

class node {
    int value;
    node* left;
    node* right;
    int height;
    friend class AVL;
};

class AVL {
    node* root;

    public:
	    AVL() { root = NULL; }
	    void insert(int n);
	    void print();
	    void print(node* p, int space);
	    int height();
	    bool balanced();
	    int height(node* n);
	    int getBalance(node* n);
	    node* rightRotate(node* y);
	    node* leftRotate(node* x);
	    node* insert(node* n, int key);
	    bool isBalanced(node* n);
	    node* deleteNode(node* x, int key);
	    void deleteNode(int key);
	    node* balanceTree(node* n, int key);
	    void updateHeights(node* x, node* y);
};

void AVL::deleteNode(int key){
	cout << "Delete: " << key << endl;
    root = deleteNode(root, key);
}

node* AVL::deleteNode(node* n, int key){
    if (n == NULL)
        return n;

    if (key < n->value) {
        n->left = deleteNode(n->left, key);
    } else if (key > n->value) {
        n->right = deleteNode(n->right, key);
    } else {
        // Node with only one child or no child
		if (n->left == NULL || n->right == NULL) {
		    node* temp;
		    if (n->left != NULL)
		        temp = n->left;
		    else
		        temp = n->right;
		
		    if (temp == NULL) {
		        // No child
		        temp = n;
		        n = NULL;
		    } else {
		        // One child
		        *n = *temp;
		    }
		    delete temp;
		} else {
            // Node with two children: get inorder successor
            node* temp = n->right;
            while (temp->left != NULL)
                temp = temp->left;
            n->value = temp->value;
            n->right = deleteNode(n->right, temp->value);
        }
    }

    if (n == NULL)
        return n;

    return balanceTree(n, key);
}

void AVL::insert(int n) {
    root = insert(root, n);
}

void AVL::print() {
    cout << "------------------" << endl;
    print(root, 1);
    cout << endl << "------------------" << endl;
}

void AVL::print(node* p, int space) {
    if(p) {
        space += C;
        print(p->right, space);
        cout << endl;
        for(int i = C; i < space; i++)
            cout << " ";
        cout << p->value << endl;
        print(p->left, space);
    } else
        return;
}

int AVL::height() {
    int h = height(root);
    cout << "Height of the tree: " << h << endl;
    return h;
}

bool AVL::balanced() {
    if (isBalanced(root))
    {
        cout << "Tree is balanced." << endl;
        return true;
    }
    else
    {
        cout << "Tree is not balanced." << endl;
        return false;
    }
}

int AVL::height(node* n) {
    if (n != NULL) {
        return n->height;
    } else {
        return 0;
    }
}

int AVL::getBalance(node* n) {
    if (n != NULL) {
        return height(n->left) - height(n->right);
    } else {
        return 0;
    }
}

void AVL::updateHeights(node* x, node* y) {
	y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
}

node* AVL::rightRotate(node* y) {
    node* x = y->left;            // x becomes the new root of the rotated subtree
    node* right_child = x->right; // will be y's new left child

    x->right = y;                 // y becomes the right child of x
    y->left = right_child;        // Move x's right subtree to y's left

    // Update heights of y and x after rotation
    updateHeights(x,y);
    return x; // Return new root
}

node* AVL::leftRotate(node* x) {
    node* y = x->right;          // y becomes the new root of the rotated subtree
    node* left_child = y->left;  // will be x's new right child

    y->left = x;                 // x becomes the left child of y
    x->right = left_child;       // Move y's left subtree to x's right

    // Update heights of x and y after rotation
    updateHeights(x,y);
    return y; // Return new root
}


node* AVL::insert(node* n, int key) {
	// tree is empty
    if (n == NULL) {
        node* newNode = new node;
        newNode->value = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

	// insert left
    if (key < n->value) {
        n->left = insert(n->left, key);
    } else if (key > n->value) { // insert right 
        n->right = insert(n->right, key);
    } else {
        return n; // Duplicate keys are not allowed
    }
    
    return balanceTree(n, key);
}

node* AVL::balanceTree(node* n, int key) {
	n->height = 1 + max(height(n->left), height(n->right));

    int balance = getBalance(n);

	// left left
    if (balance > 1 && key < n->left->value){
        return rightRotate(n);
    }

	// right right
    if (balance < -1 && key > n->right->value) {
        return leftRotate(n);
    }

	// left right
    if (balance > 1 && key > n->left->value) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

	// right left
    if (balance < -1 && key < n->right->value) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
	
	// return new root
    return n;
}

bool AVL::isBalanced(node* n) {
    if (n == NULL)
        return true;

    int lh = height(n->left);  
    int rh = height(n->right); 

    if (abs(lh - rh) <= 1 && isBalanced(n->left) && isBalanced(n->right))
        return true;

    return false;
}


int main() {
    AVL tree;
    int keys[] = {4, 2, 1, 6, 3, 5, 7, 9, 10, 11};
    for (int i = 0; i < 10; i++)
        tree.insert(keys[i]);

	//print tree
    tree.print();
    
    // show tree
    tree.height();
    
    // show balance
    tree.balanced();

	// show deletion
	// leaf
	tree.deleteNode(11);
	tree.print();
	
	// two children
	tree.deleteNode(6);
	tree.print();

	// one child
	tree.deleteNode(7); 
	tree.print();
	
	// root
	tree.deleteNode(4); 
	tree.print();
	
    return 0;
}

