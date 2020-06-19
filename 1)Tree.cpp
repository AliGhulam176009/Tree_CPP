#include<iostream>
using namespace std;


///////////////This Trunk & show code give sir//////////////
struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}
//////////////////////////////////////////////////////


class Node
{
public:
	int info;  //any data type
	Node *left; // Node pointer
	Node *right;

	//Constructor
	Node(int val) //here constructor take val
	{
		info = val;
		left = NULL;
		right = NULL;
	}

};


///////////print Tree code sir ni dya ta/////////////
void printTree(Node *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}
/////////////////////////////////////////////////////////

///////////////print print of a node//////////////////////
Node *parent(Node *curr, Node *p, Node *par)
{
//Node curr and Node par both alwasys start from root Node
// Node p those node which you find parent of p.
	if (p == par)  return NULL;

	if (curr == NULL)  return NULL;

	if (curr == p)  return par;

	else
	{
		Node *t = NULL;
		t = parent(curr->left, p, curr);
		if (t!= NULL)  //if(t!= NULL)
		{
			return t;
		}
		else
		{
			t = parent(curr->right, p, curr);
			return t;
		}
	}
}

//siblings function, parameter take root node and that value(p) node which you find sibling
Node *sibling(Node *root, Node *p)
{

	Node *par = parent(root, p, root);  //call krte vqt parameter ko declaretion nhe kre gy

	//if (par->left->info == p->info)
	if (par->left == p)
	{
		return par->right;
	}
	else
	{
		return par->left;
	}
}

/////////////////Traversal//////////////////
//preorder
void preOrder(Node *n)  //n start from root
{
	if (n == NULL)
	{
		return;
	}
	cout << n->info <<" ";
	preOrder(n->left);
	preOrder(n->right); 
}


void inOrder(Node *n)
{
	if (n==NULL)
	{
		return;
	}
	inOrder(n->left);
	cout << n->info <<" ";
	inOrder(n->right);
}


void postOrder(Node *n)
{
	if (n==NULL)
	{
		return;
	}
	postOrder(n->left);
	postOrder(n->right);
	cout << n->info <<" ";
}


/////////////getlevel////////////////////////
int getLevel(Node *ptr, int val, int level)
{ //ptr node start from root & level always start from 0
   if (ptr == NULL)
      return (0);
  	 

   if (ptr->info == val)
      return level;
   	  //cout << level <<endl;

  	return getLevel(ptr->left, val, level+1) | 
  			getLevel(ptr->right, val, level+1);

   /*int l = getLevel(ptr->left, val, level+1);
   if (l != 0)
    {
    	return l;
    } 
   else
   	{
   		return getLevel(ptr->right, val, level+1);
   
   	}*/

}


int maxDepth(Node *ptr)
{
	if (ptr == NULL)
	{
		return -1;
	}

	int maxL = maxDepth(ptr->left);
	int maxR = maxDepth(ptr->right);

	if (maxL > maxR)
	{
		return maxL+1;
	}
	return maxR+1;
}




int main()
{
	Node *root = new Node(5);
	root->left = new Node(2);
	root->right = new Node(7);
	root->left->left = new Node(5);
	root->right->right = new Node(9);
	root->right->left = new Node(30);
	root->left->right = new Node(10);
	root->left->right->right = new Node(12);
	root->left->right->right->left = new Node(3);

	printTree(root, NULL, false);

	/////////parent///////////////
	Node *n = parent(root, root->right->right, root);
	if (n == NULL){
	cout << "No parent exist"<<endl;
	return(-1);
	}
	cout<<"Parent of : "<<root->right->right->info<<" is "<<n->info<<endl;

	////////////siblings/////////////
	Node *s = sibling(root, root->left);
	cout<<"Sibling of : "<<root->left->info<<" is "<<s->info<<endl<<endl;
	//cout << root-> info <<endl;  //print root


	//Traversal
	/*Node *order = NULL;
	order = new Node(1);
	order->left = new Node(2);
	order->right = new Node(3);
	order->left->left = new Node(4);
	printTree(order, NULL, false);*/

	cout << "preOrder" <<endl;
	preOrder(root);
	cout<<endl;

	cout << "inOrder" <<endl;
	inOrder(root);
	cout<<endl;

	cout << "postOrder" <<endl;
	postOrder(root);
	cout << endl;


	Node *t = NULL;
	cout << "level of 12 is :"<<getLevel(t, 12, 0)<<endl;

	cout << "Max Depth of Tree is :"<<maxDepth(root)<<endl;

	

	return 0;
}