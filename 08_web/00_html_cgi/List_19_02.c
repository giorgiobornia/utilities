/* Write a C program that generates an HTML page with the current time */

#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{

/* Declare two variables to store the time */
time_t bintime;
struct tm *curtime;

// 	printf("Content-type: text/html\n\n");

	printf("<head>\n");
	printf("<title>Exact time (almost)</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<h1>\n");
	time(&bintime);
	curtime = localtime(&bintime);
	printf("Exact time (almost): %s\n",asctime(curtime));
	printf("</h1>\n");
	printf("</body>\n");

	return 0;
}
