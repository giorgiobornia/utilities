/* versione 1  che usa gli array*/
strcop( char s[], char t[])
{
  int i=0;
  while ((s[i] = t[i]) != '\0') i++;
}

/*versione 1.1 che usa i puntatori*/
strcop(char *s, char *t)
{
  while ((*s = *t) != '\0') {s++; t++;}
}


/* versione 2 */
strcop(char *s, char *t)
{
  while ((*s++ = *t++) != '\0') ;
}

/* versione 3 */
strcop(char *s, char *t)
{
  while (*s++ = *t++);
}
