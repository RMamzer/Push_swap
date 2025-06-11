/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:57 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/11 15:00:23 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.*/


/*
what to do in push:
1.get the node
2. move src from node to the next --> check if previous null


*/
void	push_operation(t_node **dest,t_node **src)
{
	t_node	*node;
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
