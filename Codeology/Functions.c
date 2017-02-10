#include "Functions.h"

extern int Ibeta;
extern char Srank[15];

float inputfunc()
{
	float result;
	char string[12];
	char *test;
	int check;
	int err;

	do
	{
		check = 0;
		errno = 0;
		fflush(stdout);
		fgets(string, 12, stdin);
		if (string[(strlen(string) - 1)] != '\n')
		{
			check = 1;
			while (getchar() != '\n');
		}

		result = strtof(string, &test);
		err = errno;
		if (strlen(test) > 1 || err != 0 || check == 1 || result < 1)
		{
			check = 1;
			printf("Please input a valid number!\n");
		}
	} while (check);
	return result;
}

void value(char *name, char *date, char *donation)
{ 
	int days;
	int donate;

	days = ((int)time(NULL) - (strtol(date, NULL, 10))) / 86400;
	donate = strtol(donation, NULL, 10);
	Ibeta = (strlen(name) * 2) + ((days + donate) * .5);

	if (Ibeta >= 1000)
	{
		strncpy_s(Srank, 15, "Overlord", 15);
	}
	else if (Ibeta >= 850)
	{
		strncpy_s(Srank, 15, "High Lord", 15);
	}
	else if (Ibeta >= 700)
	{
		strncpy_s(Srank, 15, "Grandmaster", 15);
	}
	else if (Ibeta >= 550)
	{
		strncpy_s(Srank, 15, "Master", 15);
	}
	else if (Ibeta >= 400)
	{
		strncpy_s(Srank, 15, "Leader", 15);
	}
	else if (Ibeta >= 250)
	{
		strncpy_s(Srank, 15, "Overseer", 15);
	}
	else
	{
		strncpy_s(Srank, 15, "Underling", 15);
	}

}