
#include "philosophers.h"

void	error_message(t_philo *philo, int mode)
{
	(void) philo;

	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "what ever!\n", 11);
	exit(EXIT_FAILURE);
}
