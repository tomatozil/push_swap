/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:32:59 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:49:03 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_arr(int *arr)
{
	free(arr);
	arr = NULL;
}

void	free_double_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	copy_arr(int *from, int **to, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*to)[i] = from[i];
		i++;
	}
}

void	set_arr(int *arr, int set_num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = set_num;
		i++;
	}
}

int	is_exist(int *lis, int target, int lis_size)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (lis[i] == target)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
