#include "Functions.h"

int search(char *name)
{
	int check = 2;
	char words[100];
	char date[100];
	char donation[100];
	FILE *fp;

	fopen_s(&fp, "Users.txt", "r");
	if (fp == NULL)
	{
		printf("An error occured while trying to search!");
	}

	while (fgets(words, 100, fp) != NULL)
	{
		words[strlen(words) - 1] = '\0';
		if (strcmp(words, name) == 0)
		{
			check = 1;
			fgets(date, 100, fp);
			fgets(donation, 100, fp);
			break;
		}
	}

	fclose(fp);

	if (check == 1)
	{
		value(name, date, donation);
	}

	return check;
}

void newsave(char *input)
{
	FILE *fp;

	fopen_s(&fp, "Users.txt", "a");
	if (fp == NULL)
	{
		printf("An error occured while trying to save!");
	}

	fprintf(fp, "%s\n", input);

	fclose(fp);
}