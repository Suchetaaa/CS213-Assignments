#include <iostream>
using namespace std;

int main(){
	int noofbuildings;
	cin >> noofbuildings;
	int heights[noofbuildings];

	for (int i = 0; i < noofbuildings; i++)
	{
		cin >> heights[i];
	}
	int max_area = 0;
	int area = 0;

	for (int i = 0; i < noofbuildings; i++)
	{
		bool check = 1;
		int min;
		int j = i;
		min = heights[i];
		area = min;
		while(check == 1)
		{
			j = j-1;
			if (j>=0 and heights[j] >= min)
			{
				area += min;
			}
			else check = 0;
		}
		check = 1;
		j = i;
		while (check == 1)
		{
			j += 1;
			if (j<noofbuildings and heights[j] >= min)
			{
				area += min;
			}
			else check = 0;
		}

		max_area = max(max_area, area);
	}

	cout << max_area;
}