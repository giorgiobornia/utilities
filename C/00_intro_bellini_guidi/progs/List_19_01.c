/* hello.c: un esempio di CGI */

/* Includere cio' che serve per lo Standard Input e Output */
#include <stdio.h>

/* Dichiarare il main, come sempre */
int main(int argc, char *argv[]) 
{
/* Per prima cosa indicare un'informazione necessaria 
per l'intestazione della response HTTP                */
	printf("Content-type: text/html\n\n");
/* Inviare su Standard Output i tag HTML */
	printf("<head>\n");
	printf("<title>Hello, World</title>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<h1>Hello, World</h1>\n");
	printf("</body>\n");

	return 0;
}
