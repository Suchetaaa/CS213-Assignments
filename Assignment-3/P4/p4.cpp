#include <iostream>
#include<cstring>
using namespace std;

void linear_search(string backend[], int safe_accesses, int terms, string search)
{
	int noof_accesses = 0;
	int bad_accesses = 0;
	int index = -1;
	int i = 0;

	while (bad_accesses <= safe_accesses and i < terms and index == -1)
	{
		if (backend[i] < search)
		{
			noof_accesses += 1;
			i += 1;
		}

		if (backend[i] >= search)
		{
			noof_accesses += 1;
			bad_accesses += 1;
			if (bad_accesses > safe_accesses) break;
			if (backend[i] == search)
			{
				index = i;
				break;
			}
			else 
			{
				i += 1;
			}

		}
	}

	cout << index << endl;
	cout << noof_accesses;
}

void binary(string backend[], int safe_accesses, int terms, string search, int& noof_accesses, int& bad_accesses, int& index, int low, int high, int& search_low, int& search_high)
{
	int mid = low + (high - low)/2;
	if (backend[mid] > search)
	{
		noof_accesses += 1;
		bad_accesses += 1;
		if (bad_accesses <= safe_accesses)
		{
			binary(backend, safe_accesses, terms, search, noof_accesses, bad_accesses, index, low, mid, search_low, search_high);
		}

		else 
		{
			search_low = low;
			search_high = high;
		}
	}

	if (backend[mid] < search)
	{
		noof_accesses += 1;
		binary(backend, safe_accesses, terms, search, noof_accesses, bad_accesses, index, mid+1, high, search_low, search_high);
	}

	if (backend[mid] == search)
	{
		bad_accesses += 1;
		if (bad_accesses <= safe_accesses)
		{
			noof_accesses += 1;
			index = mid;
		}
		else 
		{
			index = -1; 
			noof_accesses += 1;
			search_low = low;
			search_high = high;
		}

	}
}

void binary_search(string backend[], int safe_accesses, int terms, string search)
{
	int noof_accesses = 0;
	int bad_accesses = 0;
	int index = -1;
	int search_low, search_high;

	binary(backend, safe_accesses-1, terms, search, noof_accesses, bad_accesses, index, 0, terms-1, search_low, search_high);

	if (index == -1)
	{
		for (int i = search_low; i <= search_high; i++)
		{
			if (backend[i] == search)
			{
				index = i; 
				noof_accesses += 1;
				bad_accesses += 1;
			}
			if (backend[i] < search)
			{
				noof_accesses += 1;
			}

			else
			{
				bad_accesses += 1;
			}

			if (bad_accesses > safe_accesses) 
			{
				index = -1; 
				break;
			}
		}
	}

	cout << index << endl;
	cout << noof_accesses << endl;


}


int main(){
	int terms;
	cin >> terms;
	string backend[terms];
	for (int i = 0; i < terms; i++)
	{
		cin >> backend[i];
	}

	string search;
	cin >> search;
	int safe_accesses = 2;

	linear_search(backend, safe_accesses, terms, search);
	binary_search(backend, safe_accesses, terms, search);

	


	
}