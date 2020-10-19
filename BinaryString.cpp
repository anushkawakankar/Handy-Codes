// Recursive C++ program to generate all binary strings
// formed by replacing each wildcard character by 0 or 1
#include <iostream>
using namespace std;

// Recursive function to generate all binary strings
// formed by replacing each wildcard character by 0 or 1
void print(string str, int index)
{
	if (index == str.size())
	{
		cout << str << endl;
		return;
	}

	if (str[index] == '?')
	{
		// replace '?' by '0' and recurse
		str[index] = '0';
		print(str, index + 1);

		// replace '?' by '1' and recurse
		str[index] = '1';
		print(str, index + 1);

		// No need to backtrack as string is passed
		// by value to the function
	}
	else
		print(str, index + 1);
}

// Driver code to test above function
int main()
{
	string str = "1??0?101";

	print(str, 0);

	return 0;
}
