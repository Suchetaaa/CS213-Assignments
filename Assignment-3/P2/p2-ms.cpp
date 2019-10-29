#include <iostream>
using namespace std;

void comb(int seq[], int low, int mid, int high)
{
	int nooofterms = (high - low) + 1;
	int dummy[nooofterms];
	int low_i = 0, high_i = 0;

	for (int k = 0; k < nooofterms; k++)
	{
		if ((low + low_i) > mid)
		{
			dummy[k] = seq[mid + 1 + high_i];
			high_i++;
		}

		else if ((mid + 1 + high_i) > high)
		{
			dummy[k] = seq[low + low_i];
			low_i++;
		}

		else if (seq[low + low_i] > seq[mid+1 + high_i])
		{
			dummy[k] = seq[mid + 1 + high_i];
			high_i ++;
		}

		else if (seq[low + low_i] < seq[mid+1 + high_i])
		{
			dummy[k] = seq[low + low_i];
			low_i++;
		}

		else if (seq[low + low_i] == seq[mid+1 + high_i])
		{
			dummy[k] = seq[low + low_i];
			k++;
			dummy[k] = seq[low + low_i];
			low_i++;
			high_i++;
		}
	}

	for (int k = 0; k < nooofterms; k++)
	{
		seq[low + k] = dummy[k];
	}

	cout << endl;
}

void mergesort(int seq[], int low, int high)
{
	if (high > low)
	{
		int mid = low + (high-low)/2;
		mergesort(seq, low, mid);
		mergesort(seq, mid+1, high);

		comb(seq, low, mid, high);
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

	mergesort(seq, 0, terms-1);

	for (int i = 0; i < terms; i++)
	{
		cout << seq[i] << " ";
	}
}