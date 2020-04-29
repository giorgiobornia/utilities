#include <stdio.h>

/*
 * If you wanted to send the SAME output both to terminal and to file,
 * you could just do it with redirection when launching the executable:
 * 
 * ./a.out > file.out
 * 
 * However, this method does not allow to differentiate the outputs
 * Instead, with the method below you could send DIFFERENT outputs to terminal and to file
 * 
 * This can be useful in several circumstances, for instance if you wanted to distinguish between 
 *   - a "human-readable" way of showing things to terminal;
 *   - a "not-so-human-readable" file storage of data, that could afterwards be passed to postprocessing programs, such as 'gnuplot'.
 */


int main() {
    
    FILE * outfiles[2];  /* Array of two FILE pointers */
    int i;
    
    outfiles[0] = stdout;
    
    /* Case of SAME output */
    outfiles[1] = fopen("file_same.out", "w");
    
    
    for (i = 0; i < 2; i++ ) {
       fprintf(outfiles[i], "Hello world \n");
    }
    
    fclose(outfiles[1]);

    
    /* Case of DIFFERENT outputs */
    outfiles[1] = fopen("file_different.out", "w");
    
     fprintf(outfiles[0], "To stdout: Hello world \n");
     fprintf(outfiles[1], "To file: Hello world \n");
    
    fclose(outfiles[1]);
    
    return 0;
}
