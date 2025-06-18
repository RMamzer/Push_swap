/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:36:21 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 15:01:28 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_node	*stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
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



