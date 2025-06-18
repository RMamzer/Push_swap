/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:27:20 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/18 16:28:10 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	splitted = NULL;
}

void	free_stack(t_node **a)
{
	t_node	*current;
	t_node	*temp;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free (temp);
	}
	*a = NULL;
}

void	errors_exit(t_node **a, char **argv, int split_used)
{
	if (split_used)
		free_split(argv);
	free_stack(a);
	write (2, "Error\n", 6);
	exit (1);
}
