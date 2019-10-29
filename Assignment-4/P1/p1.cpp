#include <iostream>
#include<vector>
using namespace std;

int max_func(int bits[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!bits[i])
			bits[i] = -1;
	}

	int present_min = 200;
	int best_min = 200;

	for (int i = 0; i < size; i++)
	{
		if (present_min > 0 and bits[i] == -1)
		{
			present_min = bits[i];
		}
		else
			present_min = present_min + bits[i];

		best_min = min(best_min, present_min);
	}

	return best_min;

}

int main(){
int size;
int ones = 0;
cin >> size;
int bits_string[size];
for (int i = 0; i < size; i++)
{
	cin >> bits_string[i];
	if (bits_string[i])
		ones++;
}

int a = max_func(bits_string, size);

cout << ones << " " << a << endl;

cout << (ones - a) << endl;
}