#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

struct que {
	int count;
	node *front;
	node *rear;
};

que *create(que *p)
{
	p = new que;
	p->front = NULL;
	p->rear = NULL;
	p->count = 0;
	return p;
}

que *enqueue(que *p, int x)
{
	if (p->rear == NULL)
	{
		p->rear = new node;
		p->front = p->rear;
	}
	else
	{
		p->rear->next = new node;
		p->rear = p->rear->next;
	}
	p->rear->data = x;
	p->rear->next = NULL;
	p->count++;
	return p;
}

pair<que*,int> dequeue(que *p, int x)
{
	if (p->front == NULL)
		cout << "Queue is empty. ";
	else
	{
		node *current;
		current = p->front;
		p->front = current->next;
		current->next = NULL;
		x = current->data;
		current = NULL;
		delete current;
	}
	return make_pair(p, x);
}

void print(que *p)
{
	if (p->front == NULL)
		cout << "Queue is empty. ";
	else
	{
		node *helper;
		helper = p->front;
		while (helper != NULL) {
			cout << helper->data << " ";
			helper = helper->next;
		}
	}
}

int main()
{	
	que *s1 = NULL;
	que *s2 = NULL;
	s1 = create(s1);
	s2 = create(s2);
	for (int i=0; i < 10; i++)
		s1 = enqueue(s1, i);
	for (int i=0; i < 5; i++) {
		pair<que*,int> f = dequeue(s1, 0);
		s1 = f.first;
		s2 = enqueue(s2, f.second);
	}
	print(s1);
	print(s2);
	
	return 0;
}
