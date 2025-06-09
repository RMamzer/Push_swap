/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:35:22 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/09 12:35:55 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
typedef struct s_node
{
		int	num;
		int	index;

		struct s_node	*next;
		struct s_node	*target;
}	t_node;


//split functions:
static void		*ft_free(char **splitted);
static size_t	ft_wlen(char const *s, char c);
static size_t	ft_wcount(char const *s, char c);
char			**ft_split(char const *s, char c);


#endif
