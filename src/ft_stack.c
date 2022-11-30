/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:46 by pcervill          #+#    #+#             */
/*   Updated: 2022/11/28 11:37:41 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stackadd(t_stack *stack, int number)
{
	t_stack	*new;
	t_stack	*aux;

	new = (t_stack *) malloc(sizeof(t_stack));
	aux = (t_stack *) malloc(sizeof(t_stack));
	new->content = number;
	new->next = NULL;
	if (stack == NULL)
	{
		stack = new;
	}
	else
	{
		aux = stack;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (stack);
}

t_stack	*ft_stackclear(t_stack *stack_a)
{
	t_stack	*cpy;
	t_stack	*aux;

	cpy = stack_a;
	while (cpy)
	{
		aux = cpy->next;
		free(cpy);
		cpy = aux;
	}
	stack_a = NULL;
	return (stack_a);
}

int	ft_stacksize(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

t_stack	*ft_create_stack(const int *buff, int count)
{
	int		i;
	t_stack	*new_list;
	t_stack	*first_element;

	new_list = (t_stack *)malloc(sizeof(t_stack));
	i = 0;
	if (!new_list)
		exit(1);
	first_element = new_list;
	while (i < count)
	{
		if (i < count - 1)
		{
			if (!new_list->next)
				exit(1);
		}
		new_list->content = buff[i];
		if (i == (count - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (first_element);
}
