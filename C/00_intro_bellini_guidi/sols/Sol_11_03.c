char *strInStr(char *s, char *t)
{
  char *v;

  while(*s != '\0') {
    if(*s == *t)
      for(v = t; *s == *v;)  {
        if(*++v == '\0') return(s-(v-t)+1);
        if(*s++ == '\0') return(NULL);
      }
    else
      s++;
  }
  return(NULL);
}
