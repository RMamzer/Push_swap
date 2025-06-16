/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:36:21 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/16 15:55:31 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//NEED TO WORK ON A CONTENT and what is inside of node

t_node	*get_last_node(t_node	*stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_node(t_node **a, int num, char **argv, int split_used)
{
	t_node	*new_node;
	t_node	*last_node;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		errors_exit(a, argv, split_used);
//will update the variables in nodes for algorithm --> optimize info
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

t_node	*get_max_node(t_node	*node)
{
	t_node	*max_node;

	if (node == NULL)
		return (NULL);
	max_node = node;
	while (node != NULL)
	{
		if	(max_node->nbr < node->nbr)
			max_node = node;
		node = node->next;
	}
	return (max_node);
}

t_node	*get_min_node(t_node	*node)
{
	t_node	*min_node;

	if (node == NULL)
		return (NULL);
	min_node = node;
	while (node != NULL)
	{
		if	(min_node->nbr > node->nbr)
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

int	stack_size(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
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
