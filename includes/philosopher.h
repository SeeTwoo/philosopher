#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define ARG_NUMBER "invalid argument number.\n"
# define INVALID_ARG "invalid argument. Arguments can only contain digits\n"

typedef struct s_phvar	t_phvar;

struct s_phvar
{
	int	philo_number;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	max_meal;
}

#endif
