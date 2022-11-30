/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:23:49 by pcervill          #+#    #+#             */
/*   Updated: 2022/11/30 09:53:19 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
}

int	ft_error(char *error)
{
	printf("%s%s", RED, error);
	exit(EXIT_FAILURE);
}

void	init_struct(t_stacks *stacks)
{
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}

int	main(int argc, char *argv[])
{
	t_stacks	*stack;
	int			i;

	atexit(leaks);
	stack = (t_stacks *) malloc(sizeof(t_stacks));
	init_struct(stack);
	if (argc > 1)
	{
		checkparams(argv);
		stack->number = strnumber(argv, argc);
		i = 0;
		while (stack->number[i])
			stack->a = stackadd(stack->a, stack->number[i++]);
		printf("Total de numeros: %d\n", ft_stacksize(stack->a));
		while (stack->a)
		{
			printf("	%d\n", stack->a->content);
			stack->a = stack->a->next;
		}
		printf("------- -------\n STACK A	STACK B\n");
		stack->a = ft_stackclear(stack->a);
		free(stack);
	}
	return (0);
}
