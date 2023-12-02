# include <stdio.h>
# include <string.h>

int findOccurence(char sentence[], char word[])
{
	int count = 0;
	int wordsize;
	char * sentencePtr = sentence;
	while (strstr(sentencePtr, word) != NULL)
	{
		char * address = strstr(sentencePtr,word);
		sentencePtr = address+strlen(word);
		count++;
	}

	return count;
}

int main(void)
{
	char sentence[] = "this and this was known to me while this, that and this was not this this this.";
	char word[] = "this";

	int count = findOccurence(sentence, word);

	printf("%d \n", count);
	return 0;
}
