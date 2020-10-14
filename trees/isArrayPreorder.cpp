// Check if a given array can represent Preorder Traversal of Binary Search Tree

// simple approach - O(n^2)
// 1) Find the first greater value on right side of current node.
//    Let the index of this node be j. Return true if following
//    conditions hold. Else return false
//     (i)  All values after the above found greater value are
//          greater than current node.
//     (ii) Recursive calls for the subarrays pre[i+1..j-1] and
//          pre[j+1..n-1] also return true.

// Efficient using Next Greatest Element algo - O(n)

// 1) Create an empty stack.
// 2) Initialize root as INT_MIN.
// 3) Do following for every element pre[i]
//      a) If pre[i] is smaller than current root, return false.
//      b) Keep removing elements from stack while pre[i] is greater
//         then stack top. Make the last removed item as new root (to
//         be compared next).
//         At this point, pre[i] is greater than the removed root
//         (That is why if we see a smaller element in step a), we
//         return false)
//      c) push pre[i] to stack (All elements in stack are in decreasing
//         order)

// C++ program for an efficient solution to check if
// a given array can represent Preorder traversal of
// a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;

bool canRepresentBST(int pre[], int n)
{
	// Create an empty stack
	stack<int> s;

	// Initialize current root as minimum possible
	// value
	int root = INT_MIN;

	// Traverse given array
	for (int i=0; i<n; i++)
	{
		// If we find a node who is on right side
		// and smaller than root, return false
		if (pre[i] < root)
			return false;

		// If pre[i] is in right subtree of stack top,
		// Keep removing items smaller than pre[i]
		// and make the last removed item as new
		// root.
		while (!s.empty() && s.top()<pre[i])
		{
			root = s.top();
			s.pop();
		}

		// At this point either stack is empty or
		// pre[i] is smaller than root, push pre[i]
		s.push(pre[i]);
	}
	return true;
}

// Driver program
int main()
{
	int pre1[] = {40, 30, 35, 80, 100};
	int n = sizeof(pre1)/sizeof(pre1[0]);
	canRepresentBST(pre1, n)? cout << "truen":
							cout << "falsen";

	int pre2[] = {40, 30, 35, 20, 80, 100};
	n = sizeof(pre2)/sizeof(pre2[0]);
	canRepresentBST(pre2, n)? cout << "truen":
							cout << "falsen";

	return 0;
}
