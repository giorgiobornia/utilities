#include <stdio.h>

int main() {
    
FILE *fp;
char buffer[81];

fp = fopen("c:\\autoexec.bat", "r"); 
printf("\nIl file autoexec.bat contiene: ");
while(fgets(buffer, 80, fp) !=NULL) printf(buffer);
fclose(fp);

}
