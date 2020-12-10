#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

node *create()
{
	node *p;
	p = NULL;
	return p;
}

node *push(node *p, int x)
{
	if (p == NULL)
	{
		p = new node;
		p->data = x;
		p->next = NULL;
	}
	else
	{
		node *current;
		current = new node;
		current->data = x;
		current->next = p;
		p = current;
		current = NULL;
		delete current;
	}
	return p;
}

pair<node*, int> pop(node *p, int x)
{
	if (p == NULL)
		cout << "Stack is empty ";
	node *current;
	current = p;
	p = p->next;
	current->next = NULL;
	return make_pair(p, current->data);
}

void print(node *p)
{
	if (p == NULL)
		cout << "Stack is empty.";
	else
	{
		while (p != NULL) {
			cout << p->data << "\n";
			p = p->next;
		}
	}
}

int main()
{
    node *stack1;
    stack1 = create();
    node *stack2;
    stack2 = create();

    for (int i=0; i < 7; i++)
        stack1 = push(stack1, i);
    cout << "Stack 1: \n";	
    print(stack1);
	
    for (int i=0; i < 3; i++)
    {
	pair<node*, int> temp = pop(stack1, 0);
        stack1 = temp.first;
        stack2 = push(stack2, temp.second);
    }
	cout << "Stack 2: \n";
    print(stack2);
	cout << "Stack 1: \n";
    print(stack1);

    return 0;
}

