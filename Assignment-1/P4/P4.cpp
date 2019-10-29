#include <iostream>

using namespace std;

int main() {
	int lec_duration, divya_awake_mins;
	cin >> lec_duration >> divya_awake_mins;
	int theorems[lec_duration], behavior[lec_duration];

	for (int i=0; i < lec_duration; i++) {
		cin >> theorems[i];
	}

	for (int i=0; i < lec_duration; i++) {
		cin >> behavior[i];
	}

	int best_sum = 0;
	int sum = 0;

	for (int i=0; i <= (lec_duration-divya_awake_mins); i++) {
		for (int j = 0; j < divya_awake_mins; j++) {
			if (behavior[i+j] == 0) {
				sum = sum + theorems[i+j];
			}
		}
		best_sum = max(best_sum, sum);
		sum = 0;
		
	}

	int max_theorems = best_sum;
	for (int i = 0; i < lec_duration; i++) {
		if (behavior[i] == 1) {
			max_theorems = max_theorems + theorems[i];
		}
	}

	cout << max_theorems << endl;
 
}