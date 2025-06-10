/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:35:22 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/10 14:15:54 by rmamzer          ###   ########.fr       */
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
	//	int	index;

		struct s_node	*next;
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
void	ft_free_split(char **splitted);
void	free_stack(t_node **a);
void	errors_exit(t_node **a, char **argv, int split_used);
#endif
