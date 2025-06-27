#include<iostream>
#define SPACE 10

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class AVLTree
{

public:
    TreeNode* root;
    AVLTree()
    {
        root = NULL;
    }

    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Get Height  
    int height(TreeNode* r)
    {
        if (r == NULL)
            return -1;
        else {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    // Get Balance factor of node N  
    int getBalanceFactor(TreeNode* n)
    {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation  
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation  
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode* insert(TreeNode* r, TreeNode* new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            cout << "Value inserted successfully" << endl;
            return r;
        }

        if (new_node->value < r->value)
        {
            r->left = insert(r->left, new_node);
        }

        else if (new_node->value > r->value)
        {
            r->right = insert(r->right, new_node);
        }

        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left Left Case  
        if (bf > 1 && new_node->value < r->left->value)
            return rightRotate(r);

        // Right Right Case  
        if (bf < -1 && new_node->value > r->right->value)
            return leftRotate(r);

        // Left Right Case  
        if (bf > 1 && new_node->value > r->left->value) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Left Case  
        if (bf < -1 && new_node->value < r->right->value) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;

    }


    TreeNode* minValueNode(TreeNode* node)
    {
        TreeNode* current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }


    TreeNode* deleteNode(TreeNode* r, int v)
    {
        // base case 
        if (r == NULL)
        {
            return NULL;
        }

        else if (v < r->value) {
            r->left = deleteNode(r->left, v);
        }

        else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted 
        else
        {
            // node with only one child or no child 
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
            else
            {

                TreeNode* temp = minValueNode(r->right);

                r->value = temp->value;

                r->right = deleteNode(r->right, temp->value);

            }
        }

        int bf = getBalanceFactor(r);

        // Left Left Imbalance/Case or Right rotation 
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);

        // Left Right Imbalance/Case or LR rotation 
        else if (bf == 2 && getBalanceFactor(r->left) == -1)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Right Imbalance/Case or Left rotation	
        else if (bf == -2 && getBalanceFactor(r->right) <= -0)
            return leftRotate(r);
        // Right Left Imbalance/Case or RL rotation 

        else if (bf == -2 && getBalanceFactor(r->right) == 1)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode* r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE; // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
            cout << " "; // 5.1  
        cout << r->value << "\n"; // 6
        print2D(r->left, space); // Process left child  7
    }




};

int main()
{
    AVLTree tree;
   
    TreeNode* r = new TreeNode;
    r->value = 10;
    tree.root = tree.insert(tree.root, r);


    TreeNode* s = new TreeNode;
    s->value = 20;
    tree.root = tree.insert(tree.root, s);

   

    TreeNode* t = new TreeNode;
    t->value = 30;
    tree.root = tree.insert(tree.root, t);

   
    TreeNode* u = new TreeNode;
    u->value = 40;
    tree.root = tree.insert(tree.root, u);
  

    TreeNode* x = new TreeNode;
    x->value = 50;
    tree.root = tree.insert(tree.root, x);
    

    TreeNode* y = new TreeNode;
    y->value = 25;
    tree.root = tree.insert(tree.root, y);
 
    tree.print2D(tree.root, 5);



}