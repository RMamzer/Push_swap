/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:35:22 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 17:36:33 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	int				above_median;
	int				push_price;
	int				best_move;
	struct s_node	*next;
	struct s_node	*previous;
	struct s_node	*target;
}	t_node;

//push_swap
void	create_stack_a(t_node **a, char **argv, int split_used);
void	sort_big(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	sort_stack(t_node **a, t_node **b);
int		main(int argc, char **argv);

//free_and_exit
void	free_split(char **splitted);
void	free_stack(t_node **a);
void	errors_exit(t_node **a, char **argv, int split_used);

//check_functions
int		check_only_digits(char *str);
int		ft_atoi_limits(const char *nptr, t_node **a, char **argv,
			int split_used);
int		check_duplicates(t_node **a, int num);
void	add_node(t_node **a, int num, char **argv, int split_used);
int		stack_is_sorted(t_node *a);

//node_utils
t_node	*get_last_node(t_node	*stack);
t_node	*get_max_node(t_node	*node);
t_node	*get_min_node(t_node	*node);;
int		stack_size(t_node *node);
int		stack_size(t_node *node);

//sort_big_node_info
void	update_nodes_info(t_node *a, t_node *b, char c);
void	calculate_index(t_node *node);
void	find_target_a(t_node *a, t_node *b);
void	find_target_b(t_node *a, t_node *b);
void	find_push_price(t_node *src, t_node *dest);

//sort_big_node_move
t_node	*find_best_move(t_node	*node);
void	complete_rotation_a(t_node **a, t_node **b, t_node *node,
			t_node *target_node);
void	complete_rotation_b(t_node **b, t_node **a, t_node *node,
			t_node *target_node);
void	push_best_node(t_node **src, t_node **dest, char c);
void	finalize_stack_a(t_node **a);

//push_operations
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
//swap_operations
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
//rotate_operations
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
//reverse_rotate_operations
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
#endif
