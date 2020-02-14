/* Write a C program that generates a mini HTML page with Hello World 
   Redirect the run to file.html
   Open file.html with any Web browser
 */

#include <stdio.h>

int main(int argc, char *argv[]) 
{
     
/* Inviare su Standard Output i tag HTML */
	printf("<head>\n");
	printf("<title>Hello, World</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<h1>Hello, World</h1>\n");
	printf("</body>\n");

	return 0;
}
