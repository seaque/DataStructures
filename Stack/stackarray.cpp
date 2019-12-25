#include <iostream>
#include <stack>

using namespace std;

struct st {
	int boyut;
	int top;
	int *d;
};

st *create() 
{
	st *s =	new st;
	s->boyut = 2;
	s->top = -1;
	s->d = NULL;
	return s;
}

void push(st *s, int x)
{
	if (s->top == -1)
		s->d = new int[s->boyut];
	if (s->top >= s->boyut)
	{
		int *d2;
		d2 = new int[s->boyut*2];
		for (int i=0; i <= s->top; i++)
			d2[i] = s->d[i];
		s->d = d2;
		d2 = NULL;
		delete d2;
		s->boyut = s->boyut*2;
	}
	s->d[++(s->top)] = x;
}

int pop(st *s)
{
	if (s->top == -1)
		cout << "Stack bos." << " ";
	else
	{
		if (s->top <= s->boyut/2)
		{
			int *d2;
			d2 = new int[s->boyut/2];
			for (int i=0; i <= s->top; i++)
				d2[i] = s->d[i];
			s->d = d2;
			d2 = NULL;
			delete d2;
			s->boyut = s->boyut/2;
		}
	}
	return s->d[(s->top)--];
}

void print(st *s)
{
	for (int i = s->top; i > -1; i--)
		cout << s->d[i] << "\n";
}

int main()
{
	st *stack1, *stack2;
	stack1 = create();
	stack2 = create();
	for (int i=0; i < 5; i++)
		push(stack1, i);		
	push(stack2, pop(stack1));
	print(stack1);
	print(stack2);
	
	system("pause");
	return 0;
}
