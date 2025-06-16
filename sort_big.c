/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:55:56 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/16 15:58:17 by rmamzer          ###   ########.fr       */
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





void	find_target_a(t_node *a, t_node *b)
{
	t_node	*b_check;

	while (a!= NULL)
	{
		b_check = b;
		while (b != NULL)
		{
			if (a->nbr > b_check->nbr
				&& (a->target == NULL || a->target->nbr < b_check->nbr))
				a->target = b_check;
			b = b_check->next;
		}
		if (a->target == NULL)
			a->target = get_max_node(b);
		a = a->next;
	}
}

void	find_target_b(t_node *a, t_node *b)
{
	t_node	*a_check;

	while (b!= NULL)
	{
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


void	update_nodes_info(t_node *a, t_node *b, char c)
{
	calculate_index (a);
	calculate_index (b);
	if (c =='a')
	{
		find_target_a(a,b);
		find_push_price(a,b);
	}
	else
	{
		find_target_b(a,b);
		find_push_price(a,b);
	}

}

void complete_rotation_a(t_node **src, t_node **dest, t_node *node,
	 t_node *target_node)
{
	while (*src != node)
	{
		if (node->above_median)
			ra(src);
		else
			rra(src);
	}
	while (*dest != target_node)
	{
		if (target_node->above_median)
			rb(dest);
		else
			rrb(dest);
	}
}

void complete_rotation_b(t_node **src, t_node **dest, t_node *node,
	 t_node *target_node)
{
	while (*src != node)
	{
		if (node->above_median)
			rb(src);
		else
			rrb(src);
	}
	while (*dest != target_node)
	{
		if (target_node->above_median)
			ra(dest);
		else
			rra(dest);
	}
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
				rr(src,dest);
			else
				rrr(src,dest);
		}
	}
	if (c == 'a')
		complete_rotation_a(src, dest, node, target_node);
	else if (c =='b')
		complete_rotation_b(src, dest, node, target_node);
}



// sort_big(t_node **a, t_node **b)
// {
// 	int	size;

// 	pb(a, b);
// 	size == stack_size(*a);
// 	if (size-- >3)
// 		pb(a,b);
// 	while (size-->3)
// 	{
// 		update_nodes_info(*a, *b);
// 		push_best_node(a, b, 'a');
// 		size--;
// 	}
// 	sort_three(a);
// 	while (*b != NULL)
// 	{
// 		update_nodes_info(*b, *a);
// 		push_best_node(b, a, 'b');
// 	}

// }


void sort_big(t_node **a, t_node **b)
{
	int	size;

	pb(a, b);
	size = stack_size(*a);
	if (size-- >3)
		pb(a,b);
	while (size-->3)
	{
		update_nodes_info(*a, *b, 'a');
		push_best_node(a, b, 'a');
		size--;
	}
	sort_three(a);
	while (*b != NULL)
	{
		update_nodes_info(*b, *a, 'b');
		push_best_node(b, a, 'b');
	}


}
