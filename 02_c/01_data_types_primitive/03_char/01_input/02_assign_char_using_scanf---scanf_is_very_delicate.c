#include <stdio.h>

int main() {
    
char x, y, z; 

// // // /* =========== If there was a previous scanf ========== */
// // // 
// // // /* Portable way to flush pending input so that a user's typeahead isn't read at the next prompt */
// // // /* The "Enter" you typed previously is a "pending character", and so would be additional characters that you typed besides the 3 that were used */
// // // int c;
// // // while ((c = getchar()) != '\n' && c != EOF) { printf("Pending input characters are %c\n", c); }
// // // 
// // // /* =========== If there was a previous scanf - end ========== */


printf("Type 3 characters such that the string 'pvf' is located between the first and the second (so actually type 6 characters):");


scanf("%c pvf %c %c", &x, &y, &z);  /* Your input must contain pvf exactly between the first and second char, so it must be something such as "tpvfgm" */

printf("You typed: ");

printf("%c%c%c\n", x, y, z);

    
}
