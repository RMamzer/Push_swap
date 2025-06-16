/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:55:56 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/16 12:00:01 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_index(t_node *node)
{
	int	median;
	int	i;

	i = 0;
	median = stack_size(node)/2;
	while (node != NULL)
		{
			node->index = i;
			if (i <= median)
				node->above_median = 1;
			node = node->next;
			i++;
		}
}



/*how to find target:
- */
// void	find_target(t_node *src, t_node *dest)
// {
// 	t_node	*best_target;


// 	while (src!= NULL)
// 	{
// 		best_target = NULL;
// 		while (dest != NULL)
// 		{
// 			if (src->nbr > dest->nbr
// 				&& (best_target != NULL || best_target->nbr < dest->nbr))
// 				best_target = dest;
// 		}
// 		if (best_target == NULL)

// 		src = src->next;
// 	}

// }





void	find_target(t_node *src, t_node *dest)
{


	while (src!= NULL)
	{
		while (dest != NULL)
		{
			if (src->nbr > dest->nbr
				&& (src->target == NULL || src->target->nbr < dest->nbr))
				src->target = dest;
		}
		if (src->target == NULL)
			src->target == get_max_node(dest);

		src = src->next;
	}

}

// void find_push_price(t_node *a, t_node *b)
// {
// 	int size_a;
// 	int size_b;

// 	size_a = stack_size(a);
// 	size_b = stack_size(b);

// 	while(a)
// 	{
// 		a->push_price== a->index;
// 		if (!(a->above_median))
// 			a->push_price = size_a - (a->index);
// 		if (a->target->above_median)
// 	}
// }

void find_push_price(t_node *src, t_node *dest)
{
	int	size_src;
	int	size_dest;
	int p_target;

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


void	update_nodes_info(t_node *a, t_node *b)
{
	calculate_index (a);
	calculate_index (b);
	find_target (a,b);
	find_push_price(a,b);
}

sort_big(t_node **a, t_node **b)
{
	int	size;

	pb(a, b);
	size == stack_size(*a);
	if (size-- >3)
		pb(a,b);

	while (size-->3)
	{
		update_nodes_info(*a, *b);
	}
}


