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
		node *yrd;
		yrd = new node;
		yrd->data = x;
		yrd->next = p;
		p = yrd;
		yrd = NULL;
		delete yrd;
	}
	return p;
}

pair<node*, int> pop(node *p, int x)
{
	if (p == NULL)
		cout << "Stack bos. ";
	node *yrd;
	yrd = p;
	p = p->next;
	yrd->next = NULL;
	return make_pair(p, yrd->data);
}

void print(node *p)
{
	if (p == NULL)
		cout << "Stack bos. ";
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
	yazdir(stack1);
	
	for (int i=0; i < 3; i++)
	{
		pair<node*, int> t = pop(stack1, 0);
		stack1 = t.first;
		stack2 = push(stack2, t.second);
	}
	print(stack1);
	print(stack2);
	
	system("pause");
	return 0;
}
