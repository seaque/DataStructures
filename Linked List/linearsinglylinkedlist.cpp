#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

node *create (node *r, int x)
{
	r = new node;
	r->data = x;
	r->next = NULL;
	return r;
}

node *insert(node *r, int x) 
{
	if (r == NULL)
	{
		r = create(r, x);
	}
	else
	{
		node *curr;
		curr = r;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new node;
		curr->next->data = x;
		curr->next->next = NULL;
		curr = NULL;
		delete curr;
	}
	return r;
}

void print(node *r) 
{
	while (r != NULL)
	{	
		cout << r->data << " ";
		r = r->next;
	}
	system ("pause");
}

void deletion(node *r, int y) 
{
	node *curr;	
	curr = r;
	while (curr->next->data != y)
		curr = curr->next;
	node *temp;
	temp = curr->next;
	curr->next = temp->next;
	temp->next = NULL;
	//use(temp->data);
	delete temp;
}

node *addtohead(node *r, int x) 
{
	if (r == NULL) 
	{
		r = create(r, x);
	}
	else
	{
		node *curr;
		curr = new node;
		curr->data = x;
		curr->next = r;
		r = curr;
		curr = NULL;
		delete curr;
	}
	return r;
}

void addbetween(node *r, int x, int index) 
{
	node *curr;
	curr = r;
	if (index == 0)
		r = addtohead(r, x);
	else
	{
		while (curr->next->data != index)
			curr = curr->next;
		node *temp;
		temp = new node;
		temp->data = x;
		temp->next = curr->next;
		curr->next = temp;
		curr = NULL;
		temp = NULL;
		delete curr, temp;
	}
}

int main()
{

    return 0;
}
