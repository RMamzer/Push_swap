/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:25 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/10 17:11:08 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/libft.h"
//#include "libft.h"
#include <stdio.h>

int check_only_digits(char *str)
{
	size_t i;
	//check if NULL ptr;
	i = 0;
	if (str[i] != '-' && str[i] !='+' && !ft_isdigit(str[i]))
		return (0);
	else if(str[i] == '-' || str[i] =='+' )
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return (1);
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
			errors_exit(a, argv, split_used);
		i++;
	}
	return ((int)num * sign);
}

int	check_duplicates(t_node **a, int num)
{
	t_node	*temp;
	if (*a == NULL)
		return (1);
	temp = *a;
	while(temp != NULL)
	{
		if ( temp->number == num)
			return(0);
		temp = temp->next;
	}
	return (1);
}

void	create_stack_a(t_node **a, char **argv, int split_used)
{
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
		add_node(a, num, argv, split_used);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_node	*a;
//	t_node	*b;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL || argv[0] == NULL)
			errors_exit(&a, argv, 0);
		create_stack_a(&a, argv, 1);
		free_split (argv);
	}
	else
		create_stack_a(&a, argv + 1, 0);

//CHECK FUCTION _ DLEETE LATER
	printf("ac count =%d\n", argc);
	// check_sort(a_stack, b_stack, ac, splitted);
	printf("A stack contents:\n");
	print_stack(a);
	free_stack(&a);

	return (0);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("num: %d", stack->number);
		// Optional: print index too
		//printf(", index: %d", stack->index);
		printf("\n");
		stack = stack->next;
	}
}
