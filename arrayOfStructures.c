# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
	int year;
	char model;
	char company[20];	
} CAR;

int main (void)
{
	CAR c1;
	c1.year = 2005;
	c1.model = 'S';
	strcpy(c1.company, "Tesla Motors");

	printf("A %s model %c made in %d \n", c1.company, c1.model, c1.year);

	CAR * carDatabase = malloc(5*sizeof(CAR));

	for (int i = 0 ; i < 5 ; ++i)
	{
		scanf("%d", &carDatabase[i].year);
		scanf(" %c", &carDatabase[i].model);
		scanf("%s", carDatabase[i].company);
	}

	for (int j = 0 ; j < 5 ; ++j)
        {
                printf("%d ", carDatabase[j].year);
                printf(" %c ", carDatabase[j].model);
                printf("%s \n", carDatabase[j].company);
        }

	return 0;
}
