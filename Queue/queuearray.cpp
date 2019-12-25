#include <iostream>

using namespace std;

struct que {
	int boyut, count, front, rear;
	int *dizi;
};

que *tanimla(que *p)
{
	p = new que;
	p->boyut = 10;
	p->count = 0;
	p->dizi = NULL;
	p->front = -1;
	p->rear = -1;
	return p;
}

que *enqueue(que *p, int x)
{
	if (p->dizi == NULL)
		p->dizi = new int[p->boyut];
	if (p->rear == p->boyut - 1 && p->count != p->boyut) 
		p->rear = -1;
	if (p->count == p->boyut)
	{
		int *dizi2, k=0;
		dizi2 = new int[p->boyut * 2];
		if (p->rear > p->front)
		{
			for (int i = p->front + 1 ; i <= p->rear; i++) {
				dizi2[k] = p->dizi[i];
				k++;
			}
		}
		if (p->front >= p->rear && p->count != 0)
		{
			for (int i = p->front + 1; i < p->boyut; i++) {
				dizi2[k] = p->dizi[i];
				k++;
			}
			for (int i = 0; i <= p->rear; i++) {
				dizi2[k] = p->dizi[i];
				k++;
			}
		}
		p->dizi = dizi2;
		p->boyut *= 2;
	}
		
	p->dizi[++(p->rear)] = x;	
	p->count++;
	return p;
}

pair<que*,int> dequeue(que *p, int x) 
{
	if (p->count == 0) 
		cout << "Kuyruk bos. ";
	if (p->count <= p->boyut/2 )
	{
		int *dizi2, k = 0; 
		dizi2 = new int[p->boyut/2];

		if (p->rear > p->front) 
		{
			for (int i = p->front + 1 ; i <= p->rear; i++) {
				dizi2[i] = p->dizi[i];
			}
		}
		if (p->front >= p->rear && p->count != 0) 
		{
			for (int i = p->front + 1; i < p->boyut; i++) {
				dizi2[k] = p->dizi[i];
				k++;
			}
			for (int i = 0; i <= p->rear; i++) {
				dizi2[k] = p->dizi[i];
				k++;
			}
		}
		p->dizi = dizi2;
		p->boyut /= 2;
	}
	else
	{
		if (p->front == p->boyut - 1 && p->count != 0)
			p->front = -1;
	}
	x = p->dizi[++(p->front)];
	p->count--;
	return make_pair(p, x);
}

void yazdir(que *p)
{
	if (p->rear > p->front)
		for (int i = p->front + 1 ; i <= p->rear; i++)
			cout << p->dizi[i] << " ";
	if (p->front >= p->rear && p->count != 0)
	{
		for (int i = p->front + 1; i < p->boyut; i++)
			cout << p->dizi[i] << " ";
		for (int i = 0; i <= p->rear; i++)
			cout << p->dizi[i] << " ";
	}
	system("pause");
}

void main()
{
	que *s1 = NULL;
	s1 = tanimla(s1);
	que *s2 = NULL;
	s2 = tanimla(s2);

	for (int i=1; i <= 10; i++)
		s1 = enqueue(s1, i);
	yazdir(s1);

	for (int i=0; i <= 5; i++)
	{
		pair<que*,int> f = dequeue(s1, 0);
		s1 = f.first;
		s2 = enqueue(s2, f.second);
	}
	yazdir(s1);
	yazdir(s2);
	system("pause");
}
