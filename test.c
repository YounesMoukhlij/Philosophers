#include "philo/philosophers.h"


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
int *n;

void *routine(void *r) {
    int *num = (int *)r;
    // Lock the mutex before modifying shared resource
    pthread_mutex_lock(&mutex);
	int i = 0;
	while (i < 500)
	{
    	(*num)++;
		i++;
	}
    // Unlock the mutex after modifying shared resource
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t a1, a2;

    pthread_mutex_init(&mutex, NULL);
    n = malloc(sizeof(int));
    *n = 0;

    pthread_create(&a1, NULL, routine, n);
    pthread_create(&a2, NULL, routine, n);

    pthread_join(a1, NULL);
    pthread_join(a2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("%d\n", *n);

    free(n); // Free the allocated memory for n

    return 0;
}


// void	*routine(void *r)
// {
// 	t_data *d;

// 	int *n;
// 	(void) *n;
// 	// int i = 0;
// 	n = (int *)r;
// 	pthread_mutex_lock(&(d->t));
// 	// while (i < 100000)
// 	// {
// 		(*n)++;
// 		// i++;
// 	pthread_mutex_unlock(&(d->t));
// 	// }
// 	return (NULL);
// }

// int main()
// {
// 	pthread_t		a1;
// 	pthread_t		a2;
// 	pthread_mutex_t t;

// 	pthread_mutex_init(&t, NULL);
// 	int *n;
// 	n = malloc(sizeof(int));
// 	*n = 0;
// 	// pthread_mutex_lock(&(o.t));
// 	pthread_create(&a1, NULL, routine, n);
// 	pthread_create(&a2, NULL, routine, n);

// 	// pthread_mutex_unlock(&(o.t));
// 	pthread_join(a1, NULL);
// 	pthread_join(a2, NULL);

// 	pthread_mutex_destroy(&t);
// 	printf("%d\n", *n);
// }
