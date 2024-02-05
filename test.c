#include <stdio.h>
#include <pthread.h>

int cont = 0;

void *routine()
{
  int i;

  i = -1;
  while (++i < 1000000)
    cont++;
  return NULL;
}

int main()
{
  pthread_t tid1, tid2;

  // Create two threads, each running the routine function
  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  // Wait for both threads to finish
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  // Print the final value of the global variable cont
  printf("cont: %d\n", cont);

  return 0;
}
