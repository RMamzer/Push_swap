/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:25 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/09 16:24:04 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/libft.h"
//#include "libft.h"

int check_only_digits(char *str)
{
	size_t i;
	//check if NULL ptr;
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

int	ft_atoi_limits(const char *nptr, t_node **a, char **argv, int split_used)
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
		if ((num > INT_MAX && sign == 1)
			|| (num > (long)INT_MAX + 1 && sign == -1))
			error_exit(a, argv, split_used);
		i++;
	}
	return ((int)num * sign);
}

int	check_dulicates(t_node **a, int num)
{


}

void	create_stack_a(t_node **a, char **argv, int split_used)
{
	// check that its a num;  -----------------> DONE
	// check that its within int --------------> DONE
	// check that there are no duplicates before>NOW
	// Add to nodes
	int num;
	int i;

	num = 0;
	i = 0;
	while (argv[i])
	{
		if(!check_only_digits(argv[i]))
			errors_exit(a, argv, split_used);
		num = ft_atoi_limits(argv[i], a, argv, split_used);
		if (!check_duplicates(a, num))
			errors_exit(a, argv, split_used);
		add_node(a, num);
	}
}

int main(int argc, char ** argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], " ");
		//check if NULL?
		create_stack_a(&a, argv, 0);
		//free_split (argv);????????????????????
	}
	else
		create_stack_a(&a, argv + 1, 1);

	return (0);
}
