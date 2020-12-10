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
	que *q1 = NULL;
	que *q2 = NULL;
	q1 = create(q1);
	q2 = create(q2);
	
	for (int i=0; i < 10; i++)
		q1 = enqueue(q1, i);
	
	cout << "Queue 1: \n";
	print(q1);
	
	for (int i=0; i < 5; i++) 
	{
		pair<que*,int> f = dequeue(q1, 0);
		q1 = f.first;
		q2 = enqueue(q2, f.second);
	}
	cout << "\nQueue 2: \n";
	print(q2);
	cout << "\nQueue 1: \n";
	print(q1);
	
	return 0;
}

/*	OUTPUT
Queue 1: 
0 1 2 3 4 5 6 7 8 9
Queue 2:
0 1 2 3 4
Queue 1:
5 6 7 8 9
*/
