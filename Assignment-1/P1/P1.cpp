#include<iostream>

using namespace std;

int main() {
	int no_of_elements, x;
	cin >> no_of_elements >> x;
	int numbers[no_of_elements];
	int sum = 0;
	int sol = 0;
	cin >> numbers[0];
	for (int i = 1; i < no_of_elements; i++) {
		cin >> numbers[i];
		if (numbers[i-1] == numbers[i]) {
			sum = sum + 1;
			if ((sum + 1)> no_of_elements/2) {
				sol = numbers[i];
			}
		}
		else {
			sum = 0;
		}

	}

	if (sol == x) {
		cout << "1";
	}

	else {
		cout << "0";
	}
}