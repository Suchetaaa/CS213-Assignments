#include <iostream>

using namespace std;  

int main() {
	int no_of_entrances;
	cin >> no_of_entrances;
	int people[no_of_entrances];

	for (int i = 0; i < no_of_entrances; i++) {
		cin >> people[i];
	}

	bool check = 0;
	int present_queue = 0;
	while (true) {
		if (people[present_queue] == 0) break;
		for (int i = 0; i < no_of_entrances; i++) {
			if (people[i] != 0) people[i] --;
		}
		present_queue = (present_queue+1)%(no_of_entrances);
	}

	cout << present_queue+1 << endl;
}