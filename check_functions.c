/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:01:23 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 15:01:25 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_only_digits(char *str)
{
	size_t i;
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
		if ( temp->nbr == num)
			return(0);
		temp = temp->next;
	}
	return (1);
}

void	add_node(t_node **a, int num, char **argv, int split_used)
{
	t_node	*new_node;
	t_node	*last_node;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		errors_exit(a, argv, split_used);
	new_node->nbr = num;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->target = NULL;
	new_node->above_median = 0;

	if (*a == NULL)
		*a = new_node;
	else
	{
		last_node = get_last_node(*a);
		last_node->next = new_node;
		new_node->previous = last_node;
	}

}

int	stack_is_sorted(t_node *a)
{
	while (a->next!= NULL)
	{
		if ( a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}
