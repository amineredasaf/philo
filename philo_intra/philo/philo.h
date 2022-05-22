/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:25:16 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/10 15:19:27 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_must_eat;
	pthread_mutex_t	*forks_m;

}	t_info;

typedef struct s_philo
{
	int				id;
	int				total_m;
	long long		t_born;
	long long		l_meal;
	struct s_data	*dta;
	pthread_mutex_t	*righ_frk;
	pthread_mutex_t	*left_frk;
}	t_philo;

typedef struct s_data
{
	int				dead;
	int				ac;
	int				total_eat;
	char			**av;
	char			*join_line;
	char			**lines_tab_split;
	t_info			info;
	t_philo			philo[300];
	pthread_t		thread[300];
	pthread_mutex_t	mutex;
	pthread_mutex_t	eating_m;
	pthread_mutex_t	write_m;
}	t_data;

/***** parsing *****/
int			parsing(t_data *data);
int			to_string(t_data *data);
int			check_char(t_data *data);
int			to_splitted(t_data *data);
int			to_int(t_data *data);
int			check_data(t_data *data);
int			ft_valid(int ch);
/****** excu ******/

int			excu(t_data *data);
void		*routine(void *ptr);
int			init_mutex(t_data *data);
void		init_philo(t_data *data);
long long	time_now(void);

/***** utils *****/
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *dest, char *buff, int idx, int i);
char		*ft_dup(char *dest);
void		ft_putstr(char *str);
int			ft_error(char *str, t_data *data);
size_t		ft_strlen(const char *str);
void		print_state(t_philo *philo, char *str);
void		resting(long long time, t_philo *philo);
int			check_dead(t_data *data);

/********* Other *********/
void		info(t_data *data);

#endif
