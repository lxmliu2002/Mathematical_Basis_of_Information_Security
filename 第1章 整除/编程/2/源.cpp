#include<iostream>
using namespace std;


int gcd(int x, int y)
{
	int z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}


void main() {
	int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "gcd(a,b)=" << gcd(a, b) << endl;
	cout << "lcm(a,b)=" << lcm(a, b) << endl;

	system("pause");
}


