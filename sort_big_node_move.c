/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_node_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:52:39 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 15:01:51 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_node	*find_best_move(t_node	*node)
{
	t_node	*best_move;

	best_move = node;
	while (node)
	{
		if (node->push_price < best_move->push_price)
			best_move = node;
		node = node->next;
	}
	return (best_move);
}



void complete_rotation_a(t_node **a, t_node **b, t_node *node,
	 t_node *target_node)
{
	while (*a != node)
	{
		if (node->above_median)
			ra(a);
		else
			rra(a);
	}
	while (*b != target_node)
	{
		if (target_node->above_median)
			rb(b);
		else
			rrb(b);
	}
	pb(a,b);
}

void complete_rotation_b(t_node **b, t_node **a, t_node *node,
	 t_node *target_node)
{
	while (*b != node)
	{
		if (node->above_median)
			rb(b);
		else
			rrb(b);
	}
	while (*a != target_node)
	{
		if (target_node->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(a,b);
}

void push_best_node(t_node **src, t_node **dest, char c)
{
	t_node	*node;
	t_node	*target_node;

	node = find_best_move(*src);
	target_node = node->target;
	if (node->above_median == target_node->above_median)
	{
		while (*src != node && *dest != target_node)
		{
			if (node->above_median)
				rr(dest,src);
			else
				rrr(dest,src);
		}
	}
	if (c == 'a')
		complete_rotation_a(src, dest, node, target_node);
	else if (c =='b')
		complete_rotation_b(src, dest, node, target_node);
}


void finalize_stack_a(t_node **a)
{

	t_node	*min;

	calculate_index (*a);
	min = get_min_node(*a);

	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}

}
