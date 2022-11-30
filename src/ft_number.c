/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:59:38 by pcervill          #+#    #+#             */
/*   Updated: 2022/11/21 10:10:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	checkparams(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 45)
			{
				ft_error("ERROR:\nArgumentos no validos\n");
				exit (1);
			}
			if (argv[i][j + 1] == 45)
			{
				printf("ERROR:\nArgumentos no validos\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return ;
}

int	*strnumber(char **argv, int argc)
{
	int	*number;
	int	i;
	int	j;

	number = (int *) malloc(argc * sizeof(int));
	if (!number)
		return (0);
	i = 1;
	j = 0;
	while (argv[i])
	{
		number[j++] = ft_atoi(argv[i++]);
	}
	number[j] = '\0';
	free(number);
	return (number);
}

void	norepeat(int *number)
{
	int	i;
	int	j;

	i = 0;
	while (number[i])
	{
		j = i + 1;
		while (number[j])
		{
			if (number[i] == number[j])
			{
				printf("ERROR:\nArgumentos repetidos\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return ;
}
