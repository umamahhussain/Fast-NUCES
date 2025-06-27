#include <iostream>
using namespace std;


class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;


	TreeNode()
	{
		data = 0;
		left = right = NULL;
	}
};

class BST
{

public:
	TreeNode* root;

	BST()
	{
		root = NULL;
	}

	bool isempty()
	{
		if (root == NULL)
		{
			return true;
		}
		else
			return false;
	}

	void insert(int e)
	{
		TreeNode* n = new TreeNode;
		n->data = e;
		n->left = n->right = NULL;
		TreeNode* temp = root;

		if (root == NULL)
		{
			root = n;
			cout << "\ndata inserted on the root";
		}
		else
		{
			while (temp != NULL)
			{
				if (e < temp->data && temp->left == NULL)
				{
					temp->left = n;
					cout << "\ndata inserted on the left";
					break;
				}
				else
					if (e > temp->data && temp->right == NULL)
					{
						temp->right = n;
						cout << "\ndata inserted on the right";
						break;
					}
					else if (e < temp->data)
					{
						temp = temp->left;
					}
					else if (e > temp->data)
					{
						temp = temp->right;
					}
					else if(e==temp->data)
					{
						cout << "\nNo duplicates allowed";
						return;
					}
			}
		}
	}

	void levelorder()
	{
		;
	}

	void preorder(TreeNode* n)
	{
		if (n == NULL)
			return;

		cout << n->data << " ";
		preorder(n->left);
		preorder(n->right);
	}

	void inorder(TreeNode* n)
	{
		if (n == NULL)
			return;

		inorder(n->left);
		cout << n->data << " ";
		inorder(n->right);
	}

	void postorder(TreeNode* n)
	{
		if (n == NULL)
			return;

		postorder(n->left);
		postorder(n->right);
		cout << n->data << " ";
		
	}


	TreeNode* recursearch(int e,TreeNode* n)
	{
		TreeNode* temp = n;
		if (temp == NULL)
		{
			return NULL;
		}
		else
		{
			if (e < temp->data)
			{
				temp = temp->left;

				if (temp == NULL)
					return NULL;
				else
					recursearch(e,temp->left);
			}
			else
				if (e > temp->data)
				{
					temp = temp->right;
					if (temp == NULL)
						return NULL;
					else
						recursearch(e, temp->right);
				}

			if (e == temp->data)
			{
				cout << "\nVALUE FOUNDDD :)\n";
				return temp;
			}
			else
			{
				cout << "\nVALUE NOT FOUND :(\n";
			}
		}
	}

	int CountNode(TreeNode *n,int &count)
	{
		if (n == NULL)
			return count;
		else
		{
			CountNode(n->left, count);
			count++;
			CountNode(n->right, count);
		}
	}



	int LeafCount(TreeNode* n, int &leaf)
	{
		if (n == NULL)
			return leaf;
		else
		{	
			if (n->left ==NULL && n->right == NULL)
			{
				leaf++;
			}
			
			LeafCount(n->left, leaf);
			LeafCount(n->right, leaf);
		}
	}








	TreeNode* search(int e)
	{
		TreeNode* temp = root;
		if (temp == NULL)
		{
			return NULL;
		}
		else
		{
			while (temp != NULL)
			{
				if (e < temp->data)
				{
					temp = temp->left;
				}
				else
					if (e > temp->data)
					{
						temp = temp->right;
					}

				if (temp == NULL)
				{
					cout << "\nVALUE NOT FOUND :(\n";
					return NULL;

				}
				else
					if (temp->data == e)
					{
						cout << "\nVALUE FOUNDDD :)\n";
						return temp;
					}
			}

		}
	}

	int height(TreeNode* r)
	{
		if (r == NULL)
			return -1;
		else
		{
			/* compute the height of each subtree */
			
			int lheight = height(r->left);
			int rheight = height(r->right);
			
			/* use the larger one */
			if (lheight > rheight)
				return (lheight + 1);
			else return (rheight + 1);
		}
	}



	void printGivenLevel(TreeNode* r, int level)
	{
		if (r == NULL)
			return;

		else if (level == 0)
			cout << r->data << " ";

		else // level > 0  
		{
			printGivenLevel(r->left, level - 1);
			printGivenLevel(r->right, level - 1);
		}
	}


	void printLevelOrderBFS(TreeNode* r)
	{
		int h = height(r);
		for (int i = 0; i <= h; i++)
		{
			cout << endl;
			printGivenLevel(r, i);
		}
	}

	void Destructor(TreeNode* n)
	{
		if (n == NULL)
			return;

		Destructor(n->left);
		Destructor(n->right);
		n->data = 0;
		delete n;
	}

	~BST()
	{
		cout << "\nDestructor Called\n";
		Destructor(root);
	}

	/*int heightt(TreeNode* n)
	{
		int lheight=-1;
		int rheight = -1;

	while(n!=NULL)
	{
		n = n->left;
		lheight++;

		if (n == NULL)
			break;
		else
			if (n->right != NULL)
			{
				n = n->right;
				lheight++;
			}
				
	}
	n = root;
	while (n != NULL)
	{
		n = n->right;
		rheight++;

		if (n == NULL)
			break;
		else
			if (n->left != NULL)
			{
				n = n->left;
				rheight++;
			}
	}

	if (lheight > rheight)
		return lheight;
	else
		return rheight;
	}*/











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
		if (r == NULL)
		{
			return NULL;
		}

		else if (v < r->data)
		{
			r->left = deleteNode(r->left, v);
		}

		else if (v > r->data)
		{
			r->right = deleteNode(r->right, v);
		}

		else
		{
			// node with only one child or no child 
			if (r->left == NULL)
			{
				TreeNode* temp = r->right;
				delete r;
				return temp;
			}

			else if (r->right == NULL)
			{
				TreeNode* temp = r->left;
				delete r;
				return temp;
			}

			else
			{
				// node with two children: Get the inorder successor (smallest 
				// in the right subtree) 
				TreeNode* temp = minValueNode(r->right);

				// Copy the inorder successor's content to this node 
				r->data = temp->data;

				// Delete the inorder successor 
				r->right = deleteNode(r->right, temp->data);
				//deleteNode(r->right, temp->value); 
			}
		}
		return r;
	}
};



int main()
{
	BST obj;
	obj.insert(4);
	obj.insert(7);
	obj.insert(3);
	obj.insert(8);
	obj.insert(6);
	obj.insert(5);

	cout << "\n\nPrinting Preorder\n";
	obj.preorder(obj.root);


	cout << "\nPrinting Inorder\n";
	obj.inorder(obj.root);

	cout << "\nPrinting Postorder\n";
	obj.postorder(obj.root);

	cout << "\nCalling Level Order Traversal";
	obj.printLevelOrderBFS(obj.root);

	cout << "\nCalling Search\n";
	obj.search(70);

	cout << "\nCalling Recursive Search\n";
	obj.recursearch(70,obj.root);

	int count = 0;
	cout << "\nCalling Count Nodes\n";
	cout << obj.CountNode(obj.root, count);

	int leaf = 0;
	cout << "\nCalling Leaf Count\n";
	cout << obj.LeafCount(obj.root, leaf);

	cout << "\nCalling height\n";
	cout << obj.height(obj.root);

	cout << "\nCalling Delete\n";
	obj.deleteNode(obj.root, 4);

	cout << "\nCalling Delete; \n";
	obj.deleteNode(obj.root, 3);

	cout << "\nCalling Level Order Traversal";
	obj.printLevelOrderBFS(obj.root);


}