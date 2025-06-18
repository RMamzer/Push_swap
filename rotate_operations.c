/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:40:15 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 15:01:44 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_operation(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first = *stack;
	last = get_last_node(*stack);

	*stack = first->next;
	(*stack)-> previous = NULL;
	first->previous = last;
	first ->next = NULL;
	last->next = first;
}

void	ra(t_node **a)
{
	rotate_operation(a);
	write (1, "ra\n", 3);
}
void	rb(t_node **b)
{
	rotate_operation(b);
	write (1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_operation(a);
	rotate_operation(b);
	write (1, "rr\n", 3);
}
