#include <iostream>
using namespace std;

void calculate(int charges[], float force[], int num_charges)
{
	
}

int main(){

	int num_charges;
	cin >> num_charges;

	int charges[num_charges];
	float force[num_charges];

	for (int i = 0; i < num_charges; i++)
	{
		cin >> charges[i];
		force[i] = 0;
	}
	calculate(charges, force, num_charges);
	
}