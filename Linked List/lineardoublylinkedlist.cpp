#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
};

node *create(node *r, int x)
{
	r = new node;
	r->data = x;
	r->next = NULL;
	r->prev = NULL;
	return r;
}

node *addtotail(node *r, int x)
{
	if (r == NULL)
		r = create(r, x);
	else
	{
		node *curr;
		curr = r;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new node;
		curr->next->data = x;
		curr->next->next = NULL;
		curr->next->prev = curr;
	}
	return r;
}

node *addtohead(node *r, int x)
{
	if (r == NULL)
		r = create(r, x);
	else
	{
		node *curr;
		curr = new node;
		curr->data = x;
		curr->next = r;
		curr->prev = NULL;
		r->prev = curr;
		r = curr;
		curr = NULL;
		delete curr;
	}
	return r;
}

void addbefore(node *r, int x, int before)
{
	if (r == NULL)
		cout << " No data in linked list ";
	else
	{
		node *curr, *temp;
		curr = r;
        while (curr->data != before && curr->next != NULL)
			curr = curr->next;
		temp = curr;
		curr = new node;
		curr->data = x;
		temp->prev->next = curr;
		curr->next = temp;
	}
}

void print(node *r)
{
	if (r == NULL)
		cout << "\nEmpty list ";
	else 
	{
		while (r->next != NULL) {
			cout << r->data << " ";
			r = r->next;
		}
		cout << r->data << " ";
	}
}

int main()
{
    system("pause");
    return 0;
}
