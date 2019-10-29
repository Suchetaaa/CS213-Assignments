#include <iostream>
using namespace std;

void swap(int seq[], int i, int j)
{
	int dummy = seq[i];
	seq[i] = seq[j];
	seq[j] = dummy;
}

void partition(int seq[], int left, int right, int pivot, int& index)
{
	index = left;
	for (int i = left; i <= right; i++)
	{
		if (seq[i] < pivot)
		{
			swap(seq, i, index);
			index += 1;
		}
	}
	swap(seq, index, right + 1);
}

void quicksort(int seq[], int low, int high)
{
	if (low < high)
	{
		int pivot = seq[high];
		int index = low;
		partition(seq, low, high-1, pivot, index);

		quicksort(seq, low, index-1);
		quicksort(seq, index + 1, high);
	}
}

int main(){

	int terms;
	cin >> terms;

	int seq[terms];
	for (int i = 0; i < terms; i++)
	{
		cin >> seq[i];
	}

	quicksort(seq, 0, terms-1);

	for (int i = 0; i < terms; i++)
	{
		cout << seq[i] << " ";
	}
	
}