/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:36:21 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/10 16:04:21 by rmamzer          ###   ########.fr       */
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
//will pdate the variables in nodes for algorithm
	new_node-> number = num;
	new_node -> next = NULL;
	new_node -> target = NULL;

	if (*a == NULL)
		*a = new_node;
	else
	{
		last_node = get_last_node(*a);
		last_node->next = new_node;
	}

}
