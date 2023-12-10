#include <stdio.h>

int aToPowerB(int a , int b)
{
	if(b==0)
	{
		return 1;
	}
	else
	{
		return a*aToPowerB(a,b-1);
	}
}
int main(void)
{
	int ans = aToPowerB(3,4);
	printf("%d", ans);	
	return 0;
}
