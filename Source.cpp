#include <iostream>

using namespace std;

struct bst {
	int data;
	bst *right, *left;
};

bst *insert(bst *p, int x)
{
	if (p == NULL)
	{
		p = new bst;
		p->data = x;
		p->right = NULL;
		p->left = NULL;
	}
	else
	{
		if (p->data < x)
			p->right = insert(p->right, x);
		else
			p->left = insert(p->left, x);
	}
	return p;
}

bst *print(bst *p)
{
	if (p == NULL)
		return 0;
	else
	{
		print(p->left);
		cout << p->data << " ";
		print(p->right);
	}
}

int countnode(bst *p)
{
	if (p == NULL)
		return 0;
	else
		return countnode(p->left) + 1 + countnode(p->right);
}

int min(bst *p)
{
	if (p == NULL)
		return 0;
	else {
		while (p->left != NULL)
			p = p->left;
		return p->data;
	}
}

int max(bst *p)
{
	if (p == NULL)
		return 0;
	else {
		while (p->right != NULL)
			p = p->right;
	return p->data;
	}
}

bst *search(bst *p, int x)
{
	if (p == NULL)
		cout << "Tree is empty. ";
	if (p != NULL)
	{
		if (p->data == x)
			return p;
		if (p->data < x)
			return search(p->right, x);
		return search(p->left, x);
	}
	else
		return NULL;
}

bst *del(bst *p, int x)
{
	if (p == NULL)
		return NULL;
	if (p->data == x)
	{
		if (p->right == NULL && p->left == NULL)
			return NULL;
		if (p->right == NULL)
		{
			p->data = max(p->left);
			p->left = del(p->left, p->data);
			return p;
		}
		p->data = min(p->right);
		p->right = del(p->right, p->data);
		return p;
	}
	if (p->data < x) {
		p->right = del(p->right, x);
		return p;
	}
	p->left = del(p->left, x);
	return p;
}

void main()
{
	bst *tree1 = NULL;
	tree1 = insert(tree1, 25);
	tree1 = insert(tree1, 8);
	tree1 = insert(tree1, 15);
	tree1 = insert(tree1, 83);
	tree1 = insert(tree1, 61);
	
	print(tree1);
	system("pause");
}