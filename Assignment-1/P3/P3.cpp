#include<iostream>

using namespace std;

int main() {
	int no_of_people;
	cin >> no_of_people;
	int claws[no_of_people];
	bool alive[no_of_people];
	for (int i = 0; i < no_of_people; i++) {
		cin >> claws[i];
		alive[i] = 1;
	}
	for (int i = 0; i < no_of_people; i++) {
		for (int j=(i - claws[i]); j < i; j++) {
			alive[j] = 0;
		}
	}
	int no_of_alive = 0;
	for (int i = 0; i < no_of_people; i++) {
		if (alive[i] == 1) {
			no_of_alive++;
		}
	}
	cout << no_of_alive;
}