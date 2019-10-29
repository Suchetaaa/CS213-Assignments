#include<iostream>

using namespace std;

int main() {
	int no_of_elements;
	cin >> no_of_elements;
	int numbers[no_of_elements];
	
	for (int i = 0; i < no_of_elements; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < no_of_elements; i++) {
		for (int j = 0; j< (no_of_elements-1); j++) {
			if (numbers[j] > numbers[j+1]) {
				int temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
			}

		}
	}

	int sum = 0;
	int majority_num = -1;
	for (int i = 0; i < (no_of_elements-1); i++) {
		if (numbers[i] == numbers [i+1]) {
			sum = sum + 1;
			if ((sum + 1) > no_of_elements/2) {
				majority_num = numbers[i];
			}
		}
		else {
			sum = 0;
		}
	}
	cout << majority_num;

}