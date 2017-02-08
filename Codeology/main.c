#include <stdio.h>
#include <time.h>

int Ibeta;
char Srank[15];

int main(int argc, char** argv)
{
	int Iresult, Ianswer;
	
	printf("Welcome to the Church of Codeology!\n"
		"Here you can find out your beta value remotely.\n\n");
	
	//Search for name in file
	Iresult = Search(argv[1]);

	switch (Iresult);
		//Name exists - Give value back
		case 1:
			printf("Hello %s!\n"
				"Your beta level is: %d\n"
				"Your rank is: %s\n", argv[1], Ibeta, Srank);
			break;
		case 2:
			printf("Hello %s!\n"
				"Would you like to join the church of Codeology?\n"
					"\t1: Yes\n"
					"\t2: No\n", argv[1]);
			Ianswer = inputfunc();
			if (Ianswer = 1)
			{
				newuser();
			}
			break;
	//unix time to unix time difference
	//convert to hours and days
	printf("%d\n", time(NULL));
	getchar();
	return 0;
}