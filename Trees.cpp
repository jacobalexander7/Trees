// Edited by Jacob Coomer - Data Structures Program 7 - 12/3/2021


#include <iostream>
#include <string>
using namespace std;

struct treeNode
{
	string word;  // each node stores a word 
	int count; // extra component to track the # of each word
	treeNode* llink;
	treeNode* rlink;
};

class treeClass
{
public:
	treeClass();

	void insert(string value);

	void inOrder() const;
	void postOrder() const;
	void preOrder() const;



private:
	treeNode* root;

	void inOrderTraversal(treeNode* t) const;
	void postOrderTraversal(treeNode* t) const;
	void preOrderTraversal(treeNode* t) const;


};

treeClass::treeClass()
{
	root = NULL;
}

void treeClass::insert(string value)
{
	treeNode* node = new treeNode;
	node->word = value;
	node->count = 1;   // set extra component to 1
	node->llink = NULL;
	node->rlink = NULL;

	if (root == NULL)
	{
		root = node;
	}
	else
	{
		treeNode* current = root;
		treeNode* trailCurrent = NULL;
		while (current != NULL)
		{
			trailCurrent = current;
			if (value == current->word)
			{
				current->count += 1;   // if word already in tree, only need to increment count 
				return;
			}
			else if (value > current->word)
			{
				current = current->rlink;
			}
			else
			{
				current = current->llink;
			}
		}
		if (value < trailCurrent->word)
		{
			trailCurrent->llink = node;
		}
		else
		{
			trailCurrent->rlink = node;
		}
	}
}

void treeClass::inOrder() const
{
	inOrderTraversal(root);
}

void treeClass::inOrderTraversal(treeNode* t) const
{
	if (t != NULL)
	{
		inOrderTraversal(t->llink);
		cout << t->word << t->count << " ";   // output count as well 
		inOrderTraversal(t->rlink);
	}
}

void treeClass::postOrder() const
{
	postOrderTraversal(root);
}

void treeClass::preOrder() const
{
	preOrderTraversal(root);
}

void treeClass::postOrderTraversal(treeNode* t) const
{
	if (t != NULL)
	{
		postOrderTraversal(t->llink);
		postOrderTraversal(t->rlink);
		cout << t->word << t->count <<" ";  // output count as well
	}
}

void treeClass::preOrderTraversal(treeNode* t) const
{
	if (t != NULL)
	{
		cout << t->word << t->count << " ";  //output count as well
		preOrderTraversal(t->llink);
		preOrderTraversal(t->rlink);
	}
}


int main(int argc, char** argv)
{
	treeClass t;

	string value;

	cout << "Enter a word (x to exit): ";
	cin >> value;
	while (value != "x")
	{
		t.insert(value);
		cout << "Enter a word (x to exit): ";
		cin >> value;
	}

	cout << "inorder\n";
	t.inOrder();
	cout << endl;
	cout << "postorder\n";
	t.postOrder();
	cout << endl;
	cout << "preorder\n";
	t.preOrder();
	cout << endl;


	return 0;
}

