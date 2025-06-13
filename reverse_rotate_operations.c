/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:41:33 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/13 11:48:25 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_operation(t_node **stack)
{
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = get_last_node(*stack);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next =*stack;
	*stack = last;
	last->next->previous = last;
}

void rra (t_node **a)
{
	reverse_rotate_operation(a);
	write (1, "rra\n", 4);
}

void rrb (t_node **b)
{
	reverse_rotate_operation(b);
	write (1, "rrb\n", 4);
}

void rrr (t_node **a, t_node **b)
{
	reverse_rotate_operation(a);
	reverse_rotate_operation(b);
	write (1, "rrr\n", 4);
}
