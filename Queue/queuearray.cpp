#include <iostream>

using namespace std;

struct que {
	int size, count, front, rear;
	int *arr;
};

que *create(que *p)
{
	p = new que;
	p->size = 10;
	p->count = 0;
	p->arr = NULL;
	p->front = -1;
	p->rear = -1;
	return p;
}

que *enqueue(que *p, int x)
{
	if (p->arr == NULL)
		p->arr = new int[p->size];
	if (p->rear == p->size - 1 && p->count != p->size) 
		p->rear = -1;
	if (p->count == p->size)     //Enlarging the size
	{
		int *arr2, k=0;
		arr2 = new int[p->size * 2];
		if (p->rear > p->front)
		{
			for (int i = p->front + 1 ; i <= p->rear; i++) {
				arr2[k] = p->arr[i];
				k++;
			}
		}
		if (p->front >= p->rear && p->count != 0)
		{
			for (int i = p->front + 1; i < p->size; i++) {
				arr2[k] = p->arr[i];
				k++;
			}
			for (int i = 0; i <= p->rear; i++) {
				arr2[k] = p->arr[i];
				k++;
			}
		}
		p->arr = arr2;
		p->size *= 2;
	}
		
	p->arr[++(p->rear)] = x;	
	p->count++;
	return p;
}

pair<que*,int> dequeue(que *p, int x) 
{
	if (p->count == 0) 
		cout << "Kuyruk bos. ";
	if (p->count <= p->size/2 )     //Decreasing the size
	{
		int *arr2, k = 0; 
		arr2 = new int[p->size/2];

		if (p->rear > p->front) 
		{
			for (int i = p->front + 1 ; i <= p->rear; i++) {
				arr2[i] = p->arr[i];
			}
		}
		if (p->front >= p->rear && p->count != 0) 
		{
			for (int i = p->front + 1; i < p->size; i++) {
				arr2[k] = p->arr[i];
				k++;
			}
			for (int i = 0; i <= p->rear; i++) {
				arr2[k] = p->arr[i];
				k++;
			}
		}
		p->arr = arr2;
		p->size /= 2;
	}
	else
	{
		if (p->front == p->size - 1 && p->count != 0)
			p->front = -1;
	}
	x = p->arr[++(p->front)];
	p->count--;
	return make_pair(p, x);
}

void display(que *p)
{
	if (p->rear > p->front)
		for (int i = p->front + 1 ; i <= p->rear; i++)
			cout << p->arr[i] << " ";
	if (p->front >= p->rear && p->count != 0)
	{
		for (int i = p->front + 1; i < p->size; i++)
			cout << p->arr[i] << " ";
		for (int i = 0; i <= p->rear; i++)
			cout << p->arr[i] << " ";
	}
}

int main()
{
	que *s1 = NULL;
	s1 = create(s1);
	que *s2 = NULL;
	s2 = create(s2);

	for (int i=1; i <= 10; i++)
		s1 = enqueue(s1, i);
	display(s1);

	for (int i=0; i <= 5; i++)
	{
		pair<que*,int> f = dequeue(s1, 0);
		s1 = f.first;
		s2 = enqueue(s2, f.second);
	}
	display(s1);
	display(s2);
	
    system("pause");
    return 0;
}
