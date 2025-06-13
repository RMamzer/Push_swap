/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:57 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/13 11:51:45 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	push_operation(t_node **dest,t_node **src)
{
	t_node	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;

	if (*src != NULL)
		(*src)->previous = NULL;

	node->previous = NULL;

	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->previous = node;
		*dest = node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push_operation(a,b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push_operation(b,a);
	write(1, "pb\n", 3);
}

