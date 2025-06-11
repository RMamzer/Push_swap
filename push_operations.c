/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:57 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/11 18:29:11 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_operation(t_node **dest,t_node **src)
{
	t_node	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;

	if (*src != NULL)
		(*src)->previous == NULL;

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


void	rotate_operation(t_node **stack)
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

void	reverse_rotate_operation(t_node **stack)
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
