#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

node *create(node *r, int x)
{
	r = new node;
	r->data = x;
	r->next = r;
	return r;
}

node *search(node *r, int y)
{
	if (r == NULL)
		cout << " List is empty ";
	else
	{
		node *curr;
		while (curr->data != y && curr->next != r)
			curr = curr->next;
		if (curr->data == y)
			return curr;
		else
			return NULL;
	}
}

node *addtotail(node *r, int x)
{
	if (r == NULL)
		r = create(r, x);
	else
	{
		node *curr;
		curr = r;
		while (curr->next != r)
			curr = curr->next;
		node *tmp;
		tmp = new node;
		tmp->data = x;
		tmp->next = curr->next;
		curr->next = tmp;
		curr = tmp;
		curr = NULL;
		delete curr;
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
		curr = r;
		node *tmp = NULL;
		tmp = new node;
		tmp->data = x;
		tmp->next = r;
		while (curr->next != r)
			curr = curr->next;
		curr->next = tmp;
		r = tmp;
	}
	return r;
}

node *indexadd(node *r, int x, int index)  
{
	if (r == NULL)
		r = create(r, x);
	if (index == 0)
		r = addtohead(r, x);
	else
	{
	    node *curr = r;
	    int count = 0;
		
        	while (count != index-1 && curr->next != r) {
		    curr = curr->next;
		    count++;
		}
	    node *tmp = new node;
	    tmp->data = x;
	    tmp->next = curr->next;
	    curr->next = tmp;
	}
	return r;
}

void deletion(node *r, int y)
{
	if (r == NULL)
		cout << " List is empty ";
	else
	{
		node *curr;
		curr = r;
		while (curr->next->data != y)
			curr = curr->next;
		node *tmp;
		tmp = curr->next;
		curr->next = tmp->next;
		tmp = NULL;
		delete tmp;
	}
}

node *delfromhead(node *r)
{
	if (r == NULL)
		cout << " List is empty ";
	if (r->next == r)
		r = NULL;
	else
	{
		node *curr;
		curr = r;
		while (curr->next != r)
			curr = curr->next;
		curr->next = r->next;
		r = r->next;
	}
	return r;
}

void print(node *r)
{
	if (r == NULL)
		cout << " List is empty ";
	else
	{
		node *curr;
		curr = r;
		while (curr->next != r)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << curr->data << " ";
	}
	
}

int main()
{

    system("pause");
    return 0;
}
