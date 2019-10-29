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
		size -= 1;
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

int main(){

	long long noofnos;
	cin >> noofnos;
	stack indices;
	int reference[noofnos];
	int solution[noofnos];

	for (long long i = 0; i < noofnos; i++) solution[i] = -1;

	for (long long i = 0; i < noofnos; i++)
	{
		cin >> reference[i];
	}

	for (int i = 0; i < noofnos; i++)
	{
		bool complete = 0;
		while (indices.size != 0 and complete == 0)
		{
			if (reference[indices.peek()] > reference[i])
			{
				solution[indices.peek()] = i;
				indices.pop();
			}
			else 
			{
				complete = 1;
			}
		}
		indices.push(i);
	}
	for (long long i = 0; i < noofnos; i++) 
	{
		cout << solution[i] << " ";
	}
	
}