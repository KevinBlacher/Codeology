#include <stdio.h>
#include <time.h>
#include "Functions.h"

int Ibeta;
char Srank[15];
char *title;

void usage();

int main(int argc, char** argv)
{
	int Iresult, Ianswer;
	char epoch[20];

	title = argv[0];

	if (argc != 2)
	{
		usage();
	}

	printf("Welcome to the Church of Codeology!\n"
		"Here you can find out your beta value remotely.\n\n");
	
	//Search for name in file
	Iresult = search(argv[1]);

	switch (Iresult)
	{
		//Name exists - Give value back
		case 1:
			printf("Hello %s!\n"
				"Your beta level is: %d\n"
				"Your rank is: %s\n", argv[1], Ibeta, Srank);
			getchar();
			break;
		case 2:
			printf("Hello %s!\n"
				"Would you like to join the church of Codeology?\n"
				"\t1: Yes\n"
				"\t2: No\n", argv[1]);
			Ianswer = inputfunc();
			if (Ianswer == 1)
			{
				snprintf(epoch, 20, "%d", (int)time(NULL));
				//Need input and saves for name, date, and donation
				newsave(argv[1]);
				newsave(epoch);
				newsave("0");
				value(argv[1], epoch, "0");
				printf("Congratulations! You are one of us now!\n"
					"Your beta level is: %d\n"
					"Your rank is: %s\n", Ibeta, Srank);
				getchar();
			}
			else
			{
				printf("Well then... Go back to C you harlot!!!\n");
				getchar();
			}
			break;
	}
	return 0;
}

void usage()
{
	printf("Usage:\n"
		"\t%s \"<Full Name\"", title);
	getchar();
	exit(1);
}