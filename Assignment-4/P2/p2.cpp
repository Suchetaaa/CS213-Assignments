#include <iostream>
#include <algorithm>
#include <queue> 
using namespace std;



int main(){
	priority_queue <int, vector<int>, greater<int> > min_heap;
	priority_queue <int, vector<int>, less<int> > max_heap;
	int min_size = 0, max_size = 0;


	int queries; 
	cin >> queries;
	bool break_loop = 0;

	for (int i = 0; i < queries; i++)
	{
		char query;
		cin >> query;
		if (query == 'c')
		{
			int number;
			cin >> number;

			if (min_size == 0 and max_size == 0)
			{
				max_heap.push(number);
				max_size++;
			}

			else if (min_size == 0)
			{
				if (max_heap.top() > number)
				{
					min_heap.push(max_heap.top());
					max_heap.pop();
					max_heap.push(number);
					min_size++;
				}

				else
				{
					min_heap.push(number);
					min_size++;
				}
			}

			else if (min_size > max_size)
			{
				if (min_heap.top() >= number)
				{
					max_heap.push(number);
					max_size++;
				}
				else
				{
					max_heap.push(min_heap.top());
					min_heap.pop();
					min_heap.push(number);
					max_size++;
				}
			}

			else if (max_size > min_size)
			{
				if (max_heap.top() <= number)
				{
					min_heap.push(number);
					min_size++;
				}
				else
				{
					min_heap.push(max_heap.top());
					max_heap.pop();
					max_heap.push(number);
					min_size++;
				}
			}

			else if (max_size == min_size)
			{
				if (max_heap.top() > number)
				{
					max_heap.push(number);
					max_size++;
				}
				else
				{
					min_heap.push(number);
					min_size++;
				}
			}
		}

		if (query == 'm')
		{
			if (min_size > max_size)
			{
				cout << min_heap.top() << endl;
			}

			else if (max_size > min_size)
			{
				cout << max_heap.top() << endl;
			}

			else if (max_size == min_size)
			{
				cout << double(min_heap.top() + max_heap.top())/2 << endl;
			}
		}
	}
	
}