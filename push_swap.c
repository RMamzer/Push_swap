/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:25 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/19 12:54:50 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(t_node **a, char **argv, int split_used)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (argv[i])
	{
		if (!check_only_digits(argv[i]))
			errors_exit(a, argv, split_used);
		num = ft_atoi_limits(argv[i], a, argv, split_used);
		if (!check_duplicates(a, num))
			errors_exit(a, argv, split_used);
		add_node(a, num, argv, split_used);
		i++;
	}
}

void	sort_big(t_node **a, t_node **b)
{
	int	size;

	pb(a, b);
	size = stack_size(*a);
	if (size-- > 3)
		pb(a, b);
	while (size-- > 3)
	{
		update_nodes_info(*a, *b, 'a');
		push_best_node(a, b, 'a');
	}
	sort_three(a);
	while (*b != NULL)
	{
		update_nodes_info(*a, *b, 'b');
		push_best_node(b, a, 'b');
	}
	finalize_stack_a(a);
}

void	sort_three(t_node **a)
{
	t_node	*max_node;

	max_node = get_max_node(*a);
	if (max_node == *a)
		ra(a);
	else if (max_node == (*a)->next)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	if (*a == NULL)
		return ;
	if (!stack_is_sorted(*a))
	{
		size = stack_size(*a);
		if (size == 2)
			sa(a);
		else if (size == 3)
			sort_three(a);
		else
			sort_big(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1)
		return (1);
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL || argv[0] == NULL)
			errors_exit(&a, argv, 1);
		create_stack_a(&a, argv, 1);
		free_split (argv);
	}
	else
		create_stack_a(&a, argv + 1, 0);
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
