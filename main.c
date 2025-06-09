/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:25 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/09 12:48:59 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/libft.h"
//#include "libft.h"
//functions to write error

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int check_only_digits(char *str)
{
//checck if -+or digit
//check that next is a digit
//run and check if they are digits

	size_t i;

	i = 0;
	if (str[i] != '-' || str[i] !='+' || !ft_isdigit(str[i]))
		return (1);
	else if(str[i] == '-' || str[i] =='+' )
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return(1);
		i++;
	}
	return (0);
}
void errors_exit(t_node **a)
{
	//free the node a
	//add ft_printf
	write(1, "Error\n",6);
	exit (1);
}

int	ft_atoi_limits(const char *nptr, char **argv)
{
	int		sign;
	int		i;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		if((num > INT_MAX && sign == 1) || (num > -INT_MIN || sign == -1))
		// what should i send here?? I should free
			error_exit(argv);

		i++;
	}
	return ((int)num * sign);
}




void create_stack_a (t_node **a, char **argv)
{
	// check that its a num;
	// check that its within int
	// check that there are no duplicates before
	int num;
	int i;

	num = 0;
	i = 0;
	while (argv[i])
	{
		if(!check_only_digits(argv[i]))
			errors_exit(a);
		num = ft_atoi_limits(argv[i], argv);
	}
}


int main(int argc, char ** argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], " ");
		//check if NULL?
		create_stack_a(&a, argv);
	}
	else
		create_stack_a(&a, argv + 1);
	return (0);
}

