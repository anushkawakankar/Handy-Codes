// C++ program to print all prime factors
#include <bits/stdc++.h>
using namespace std;
void primeFactors(int n)
{
	while (n % 2 == 0)
	{
		cout << 2 << " ";
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			cout << i << " ";
			n = n/i;
		}
	}
	if (n > 2)
		cout << n << " ";
}

/* Driver code */
int main()
{
	int n = 315;
	primeFactors(n);
	return 0;
}

// This is code is contributed by rathbhupendra
