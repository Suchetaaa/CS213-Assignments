#include <iostream>
using namespace std;

class stack
{
public:
	int stack_array[100000];
	int *top;
	long long size;

	stack() 
	{
		top = &stack_array[0];
		size = 0;
	}

	int pop()
	{
		top = top - 1;
		size = size - 1;
		return (*(top));
	}

	void push(int value)
	{
		(*top) = value;
		top = top + 1;
		size += 1;
	}

	int peek()
	{
		return (*(top-1));
	}

};

void enqueue(stack& stack1, stack& stack2, int value)
{
	int stack1_size = stack1.size;
	for (int i = 0; i < stack1_size; i++)
	{
		stack2.push(stack1.pop());
	}
	stack1.push(value);

	for (int i = 0; i < stack1_size; i++)
	{
		stack1.push(stack2.pop());
	}

}

void dequeue(stack& stack1, stack& stack2)
{
	stack1.pop();
}

void print_element(stack& stack1, stack& stack2)
{
	if (stack1.size == 0) cout << "-1" << endl;
	else cout << stack1.peek() << endl;
}

int main(){
	int noofqueries;
	cin >> noofqueries;
	stack stack1;
	stack stack2;
	for (int i = 0; i < noofqueries; i++)
	{
		int action;
		cin >> action;
		
		if (action == 1)
		{
			int value;
			cin >> value;
			enqueue(stack1, stack2, value);
		}
		if (action == 2)
		{
			dequeue(stack1, stack2);
		}
		if (action == 3)
		{
			print_element(stack1, stack2);
		}
		

	}
}