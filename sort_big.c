/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:55:56 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/13 18:30:50 by rmamzer          ###   ########.fr       */
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


void	update_nodes_info(t_node *a, t_node *b)
{
	calculate_index (a);
	calculate_index (b);
	find_target (a,b);
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


