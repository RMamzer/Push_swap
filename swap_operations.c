/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:53:19 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 16:25:12 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_operation(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || ((*stack)->next == NULL))
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	first->previous = second;
	*stack = second;
}

void	sa(t_node **a)
{
	swap_operation(a);
	write (1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap_operation(b);
	write (1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap_operation(a);
	swap_operation(b);
	write (1, "ss\n", 3);
}
