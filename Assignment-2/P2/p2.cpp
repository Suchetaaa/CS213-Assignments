#include <iostream>
using namespace std;

class entity 
{
public:
	long long petrol;
	long long distance;
};

class circular_array
{
public:
	entity array[100000];

	void insert(long long index, long long petrol_val, long long distance_val)
	{
		array[index].petrol = petrol_val;
		array[index].distance = distance_val;
	}

};

int main(){
	
	long long max_pumps;
	cin >> max_pumps;
	circular_array petrol_pumps;
	long long start_tour = -1;
	for (long long i = 0; i < max_pumps; i++)
	{
		long long petrol, distance;
		cin >> petrol >> distance;
		petrol_pumps.insert(i, petrol, distance);

	}

	long long petrol_current = 0;
	for (long long i = 0; i < max_pumps; i++)
	{
		petrol_current = 0;
		for (long long j = 0; j < max_pumps+1; j++)
		{
			long long k = (i+j)%max_pumps;
			petrol_current += petrol_pumps.array[k].petrol;
			if (petrol_current < petrol_pumps.array[k].distance) break;

			if (j != 0 and k == i) {
				start_tour = i;
				break;
			}

			petrol_current -= petrol_pumps.array[k].distance;


		}
		if (start_tour != -1) break;
	}

	cout << start_tour << endl;
	
}














