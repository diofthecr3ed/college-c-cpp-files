#include <stdio.h>
#include <string.h>
void wordReverse(char word[], int len);
int main(void)
{
	char word[] = "PlakshaUniversity";
	wordReverse(word, -1);
	return 0;
}

void wordReverse(char word[], int len)
{
	if(len == strlen(word))
	{
		return;
	}
	else
	{	
		len++;
		printf("%c", word[strlen(word)-len]);
		wordReverse(word,len);
	}
}
