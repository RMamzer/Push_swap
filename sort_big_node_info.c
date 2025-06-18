/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_node_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:55:56 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 16:33:57 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_nodes_info(t_node *a, t_node *b, char c)
{
	calculate_index(a);
	calculate_index(b);
	if (c == 'a')
	{
		find_target_a(a, b);
		find_push_price(a, b);
	}
	else
	{
		find_target_b(a, b);
		find_push_price(b, a);
	}
}

void	calculate_index(t_node *node)
{
	int	median;
	int	i;

	i = 0;
	median = stack_size(node) / 2;
	while (node != NULL)
	{
		node->index = i;
		if (i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		i++;
	}
}

void	find_target_a(t_node *a, t_node *b)
{
	t_node	*b_check;

	while (a != NULL)
	{
		a->target = NULL;
		b_check = b;
		while (b_check != NULL)
		{
			if (a->nbr > b_check->nbr
				&& (a->target == NULL || a->target->nbr < b_check->nbr))
				a->target = b_check;
			b_check = b_check->next;
		}
		if (a->target == NULL)
			a->target = get_max_node(b);
		a = a->next;
	}
}

void	find_target_b(t_node *a, t_node *b)
{
	t_node	*a_check;

	while (b != NULL)
	{
		b->target = NULL;
		a_check = a;
		while (a_check != NULL)
		{
			if (b->nbr < a_check->nbr
				&& (b->target == NULL || b->target->nbr > a_check->nbr))
				b->target = a_check;
			a_check = a_check->next;
		}
		if (b->target == NULL)
			b->target = get_min_node(a);
		b = b->next;
	}
}

void	find_push_price(t_node *src, t_node *dest)
{
	int	size_src;
	int	size_dest;
	int	p_target;

	size_src = stack_size(src);
	size_dest = stack_size(dest);
	while (src)
	{
		p_target = 0;
		if (src->above_median)
			src->push_price = src->index;
		else
			src->push_price = size_src - (src->index);
		if (src->target->above_median)
			p_target = src->target->index;
		else
			p_target = size_dest - (src->target->index);
		if (src->above_median != src->target->above_median)
			src->push_price += p_target;
		else if (src->push_price < p_target)
			src->push_price = p_target;
		src = src->next;
	}
}
