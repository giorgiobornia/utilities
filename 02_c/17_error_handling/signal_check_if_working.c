#include <signal.h>
#include <string.h>
 #include <sys/time.h>
 #include <stdio.h>

// The following code sets a `timebomb'. After {\tt Timer} is called,
// the program will continue execution until `{\tt n}' milliseconds
// have passed, then normal execution will be interrupted and 
// `{\tt onalarm()}' will be called before  normal execution is resumed. 


// This same method can be used to catch emergency signals like
// {\tt SIGBUS} (bus error) too.


static void onalarm(void)
{
    printf("hello world\n");
  signal(SIGALRM, SIG_DFL);
}


void Timer(int n)   /* waits for 'n' milliseconds */
{
  long usec;
  struct itimerval it;

  if (!n) return;

  usec = (long) n * 1000;
  
  memset(&it, 0, sizeof(it));
  if (usec >= 1000000L) {  /* more than 1 second */
    it.it_value.tv_sec = usec / 1000000L;
    usec %= 1000000L;
  }

  it.it_value.tv_usec = usec;
  signal(SIGALRM,onalarm);
  setitimer(ITIMER_REAL, &it, (struct itimerval *)0);
}


int main() {
    
    Timer(20000);
    
    
     return 0;
  
}
