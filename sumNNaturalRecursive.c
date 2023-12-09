#include <stdio.h>
// printing the sum of first n natural numbers through recursion.

int sumNNaturalRecursive(int n);

int main(void)
{
	int n = 100;
	// scanf("%d", &n)
	int sum = sumNNaturalRecursive(n);
	printf("%d\n", sum);
	return 0;
}

int sumNNaturalRecursive(int n)
{
	if(n==1)
	{
		return 1; 	
	}
	else
	{
		return n + sumNNaturalRecursive(n-1);
	}
}
