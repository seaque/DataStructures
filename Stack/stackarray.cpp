#include <iostream>

using namespace std;

struct st {
	int size;
	int top;
	int *arr;
};

st *create() 
{
	st *s =	new st;
	s->size = 2;
	s->top = -1;
	s->arr = NULL;
	return s;
}

void push(st *s, int x)
{
	if (s->top == -1)
		s->arr = new int[s->size];
	if (s->top >= s->size)
	{
        	//Creating a new array with 2x size.
		int *tmparr;
		tmparr = new int[s->size*2];
		for (int i=0; i <= s->top; i++)
			tmparr[i] = s->arr[i];
		s->arr = tmparr;
		tmparr = NULL;
		delete tmparr;
		s->size = s->size*2;
	}
	s->arr[++(s->top)] = x;
}

int pop(st *s)
{
	if (s->top == -1)
		cout << "Stack is empty." << " ";
	else
	{
		if (s->top <= s->size/2)
		{
            		//Creating a new array with 1/2x size.
			int *tmparr;
			tmparr = new int[s->size/2];
			for (int i=0; i <= s->top; i++)
				tmparr[i] = s->arr[i];
			s->arr = tmparr;
			tmparr = NULL;
			delete tmparr;
			s->size = s->size/2;
		}
	}
	return s->arr[(s->top)--];
}

void print(st *s)
{
	for (int i = s->top; i > -1; i--)
		cout << "Data [" << i << "]: " << s->arr[i] << "\n";
}

int main()
{
	st *stack1, *stack2;
	stack1 = create();
	stack2 = create();
	
    	for (int i=0; i < 10; i++) 
		push(stack1, i);	
    	for (int i=0; i < 4; i++)
    		push(stack2, pop(stack1));
	//First 5 element of stack1 is now stack2.
    
    	print(stack1);
	print(stack2);
	
	return 0;
}
