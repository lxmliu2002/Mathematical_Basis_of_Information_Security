#include<iostream>
using namespace std;
#define n 1000000
int main() 
{
	
	long int prime[n]={};
	long int count = 0;
	for (long int i = 0; i < n; i++)
	{ 
		prime[i] = 1; 
	} 
	for (long int i = 2; i < sqrt(n); i++)
	{ 
		if (prime[i] == 1) 
		{ 
			for (long int j = i * i; j < n; j += i)
			{ 
				prime[j] = 0; 
			} 
		} 
	} 
	for (long int i = 2; i < n; i++)
	{
		if (prime[i] == 1) 
		{ 
			cout << i << ","; 
			count++; 
		} 
	} 
	cout << endl;
	cout << "Total:" << count << endl; 
	return 0; 
}