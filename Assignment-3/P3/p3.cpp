#include <iostream>
#include <cstring> 
using namespace std;

string longest_prefix(string seq[], int size)
{
	string prefix = "";
	int min_len = 1000;
	for (int i = 0; i < size; i++)
	{
		if (seq[i].length() < min_len)
		{
			min_len = seq[i].length();
		}
	}
	for (int i = 0; i < min_len; i++)
	{
		string string_0 = seq[0];
		char check = string_0[i];
		int k;
		for (k = 1; k < size; k++)
		{
			string string_k = seq[k];
			if (string_k[i] != check) break;
		}
		if (k == size) 
		{
			prefix += check;
		}

		else {
			return prefix;
		}
	}
	return prefix;
}

int main(){
	int size;
	cin >> size;
	string seq[size];
	for (int i = 0; i < size; i++)
	{
		cin >> seq[i];
	}
	string final = longest_prefix(seq, size);

	if (final == "") 
	{
		cout << "-1" << endl;
	}
	else {
		cout << final << endl;
	}


	
}