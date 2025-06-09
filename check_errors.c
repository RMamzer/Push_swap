/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:27:20 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/09 18:37:22 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	splitted = NULL;
	return (NULL);
}

void	free_stack(t_node **a)
{
	t_list	*current;
	t_list	*temp;
	if (a  == NULL)
		return ;
	current = *a;
	while(current != NULL)
		temp = current;
		current = current->next;
		free (temp);
	*a = NULL;
}

void	errors_exit(t_node **a, char **argv, int split_used)
{

	if (split_used)
		ft_free_split(argv);
	free_stack(a);
	write (2, "Error\n", 6);
	exit (1);
}
