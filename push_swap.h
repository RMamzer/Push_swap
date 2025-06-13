/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:35:22 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/13 11:48:52 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
		int	number;

		struct s_node	*next;
		struct s_node	*previous;
		struct s_node	*target;
}	t_node;

//TEST FUNCTIONS:
void	print_stack(t_node *stack);


//main
int		check_only_digits(char *str);
int		ft_atoi_limits(const char *nptr, t_node **a, char **argv, int split_used);
void	create_stack_a(t_node **a, char **argv, int split_used);
int		main(int argc, char ** argv);
int		check_duplicates(t_node **a, int num);

//check_errors
void	free_split(char **splitted);
void	free_stack(t_node **a);
void	errors_exit(t_node **a, char **argv, int split_used);

//node_operations
void	add_node(t_node **a, int num, char **argv, int split_used);
t_node	*get_last_node(t_node	*stack);

//All operations---------------
//push_operations
void	push_operation(t_node **dest,t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
//swap_operations
static void	swap_operation(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node ** b);
//rotate_operations
static void	rotate_operation(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
//reverse_rotate_operations
static void	reverse_rotate_operation(t_node **stack);
void rra (t_node **a);
void rrb (t_node **b);
void rrr (t_node **a, t_node **b);
#endif
