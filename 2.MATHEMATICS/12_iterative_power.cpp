// Computing power (Binary exponenttiation)
#include <iostream>
#include <limits.h>
using namespace std;
int PowerIterative(int x, int n)
{
	int res = 1;
	while (n > 0)
	{
		if (n % 2 != 0)
		{
			res = res * x;
		}
		x = x * x;
		n = n / 2;
	}
	return res;
}

int main()
{

	int x = 4, n = 5;

	cout << PowerIterative(x, n);
}