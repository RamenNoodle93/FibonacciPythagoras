#include <iostream>
#include <vector>
#include <cmath>

/*
This simple program shows the interesting connection between the Fibonacci sequence and the Pythagorean theorem.
Example:
Given the Fibonacci sequence: 1, 1, 2, 3, 5, 8, 13, ...
It is easy to notice that the n-th element squared, plus the n+1-st element squared
is equal to the i-th element, where i is equal to double the index of the n+1-st element of the array (0-based),
meaning i = 2 * (n + 1).
E.g.
1 + 1 = 2		(n = 0, i = 2)
1 + 2*2 = 5		(n = 1, i = 4)
2*2 + 3*3 = 13	(n = 2, i = 6)
...
*/

/**
	* @brief Generates first n elements of the Fibonacci sequence.
	*
	* It non-recursively generates the first n elements of the Fibonacci sequence, using a vector.
	* 
	* @param n: How many elements of the sequence to generate.
	* 
	* @return Returns a vector containing the first n elements of the Fibonacci sequence.
*/
static std::vector<int> fibonacciSequence(int n)
{
	std::vector<int> fibonacci;
	fibonacci.push_back(1);
	fibonacci.push_back(1);
	for (int i = 2; i < n; i++)
	{
		int newVal = fibonacci[i - 1] + fibonacci[i - 2];
		fibonacci.push_back(newVal);
	}
	return fibonacci;
}

int main()
{
	std::vector<int> fibonacci = fibonacciSequence(25);

	int shift = 2;

	for (int i = 0; i < fibonacci.size() - shift; i++)
	{
		std::cout << std::pow(fibonacci[i], 2) << " + " << std::pow(fibonacci[i + 1], 2) << " = " << fibonacci[2*(i + 1)] << "\n";
		shift++;
	}

}