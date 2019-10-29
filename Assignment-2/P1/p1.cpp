#include <iostream>
using namespace std;

class stack
{
public:
	char stack_array[1000];
	char *top;

	stack() 
	{
		top = &stack_array[0];
	}

	char pop()
	{
		top = top - 1;
		return (*(top));
	}

	void push(char value)
	{
		(*top) = value;
		top = top + 1;
	}

	char peek()
	{
		return (*(top-1));
	}

};

int main(){

	stack brackets;
	bool checker = 1;
	char bracket;
	while(cin >> bracket)
	{
		if (bracket == '(' or bracket == '[' or bracket == '{') 
		{
			brackets.push(bracket);
		}

		char b;
		switch(bracket)
		{
			case ')' : 
			if (brackets.peek() == '(') 
			{
				brackets.pop();
				break;
			}
			else 
			{
				checker = 0;
				break;
			}
			case '}' : 
			if (brackets.peek() == '{') 
				{
					brackets.pop();
					break;
				}
			else 
			{
				checker = 0;
				break;
			}
			case ']' : 
			if (brackets.peek() == '[') 
				{
					brackets.pop();
					break;
				}
			else 
			{
				checker = 0;
				break;
			}

		}

		if (checker == 0) 
		{
			break;
		}


	}

	cout << checker;
	
}