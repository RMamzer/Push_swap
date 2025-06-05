/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:25 by rmamzer           #+#    #+#             */
/*   Updated: 2025/06/05 19:50:46 by rmamzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
//#include "libft.h"
//functions to write error




int check_only_digits(char *str)
{
	
}

void errors_exit(t_node **a)
{
	//free the node a
	//add ft_printf
	ft_printf("Error\n");
	exit (1);
}

create_stack_a (t_node **a, char **argv)
{
	// check that its a num;
	// check that its within int
	// check that there are no duplicates before

	int num;
	int i;

	num = 0;
	i = 0;
	while (argv[i])
	{
		if(!check_only_digits(argv[i]))
			errors_exit(a);
	return (0);
	}
	
}


int main(int argc, char ** argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = NULL;
	b = NULL;
	if (argc == 2)
		argv = ft_split(argv[1], " ");
	
	create_stack_a(&a, argv + 1);
	return (0);
	
}

