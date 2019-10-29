#include <iostream>
#include<vector>
using namespace std;

class polynomial
{
public:
	int noof_terms;
	vector<int> coeffs;
	vector<int> powers;
public:
	polynomial(int noof_terms_input, vector<int> coeffs_input, vector<int> powers_input)
	{
		noof_terms = noof_terms_input;
		coeffs = coeffs_input;
		powers = powers_input;
	}


	polynomial add(polynomial p2) const
	{
		int highest_coeff = max(p2.powers[p2.noof_terms-1], powers[noof_terms-1]);
		cout << highest_coeff << endl;
		int coeff_result[highest_coeff];
		for (int i = 0; i <= highest_coeff; i++) {
			coeff_result[i] = 0;
		}
		for (int i = 0; i< p2.noof_terms; i++)
		{
			coeff_result[p2.powers[i]] += p2.coeffs[i];
		}
		for(int i = 0; i < noof_terms; i++)
		{
			bool found = 0;
			for (int j = 0; j < p2.noof_terms; j++)
			{
				if (i == j) 
				{
					coeff_result[powers[i]] += (coeffs[i]);
					found = 1;

				}
				
			}
			if (found == 0)
			{
				coeff_result[powers[i]] = coeffs[i];
			}
		}


		int j = 0;
		vector<int> final_coeffs;
		vector <int> final_powers;
		for (int i = 0; i <= highest_coeff; i++)
		{
			if(coeff_result[i] != 0)
			{
				final_coeffs.push_back(coeff_result[i]);
				final_powers.push_back(i);
				j += 1;
			}
		}
		polynomial result(j, final_coeffs, final_powers);
		return result;
	}
	
	
};



int main(){

	int terms;
	cin >> terms;
	vector <int> coefficients;
	vector <int> power;
	int dummy;

	for (int i = 0; i < terms; i++)
	{
		cin >> dummy;
		coefficients.push_back(dummy);
	}

	for (int i = 0; i < terms; i++)
	{
		cin >> dummy;
		power.push_back(dummy);
	}

	polynomial poly_1(terms, coefficients, power);
	vector <int> coefficients2;
	vector <int> power2;

	cin >> terms;
	for (int i = 0; i < terms; i++)
	{
		cin >> dummy;
		coefficients2.push_back(dummy);
	}

	for (int i = 0; i < terms; i++)
	{
		cin >> dummy;
		power2.push_back(dummy);
	}

	polynomial poly_2(terms, coefficients2, power2);

	polynomial mul = poly_1.add(poly_2);
	cout << mul.noof_terms << endl;

	for (int i = 0; i < mul.noof_terms; i++)
	{
		cout << mul.coeffs[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < mul.noof_terms; i++)
	{
		cout << mul.powers[i] << " ";
	}

	
}



