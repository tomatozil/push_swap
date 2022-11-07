/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:12:20 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:12:34 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_to_put(int *tmp, t_node *cur, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tmp[i] == -1 || tmp[i] >= cur->data)
			break ;
		i++;
	}
	tmp[i] = cur->data;
	return (i);
}

int	get_max_in_lis(int *lis, int size)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	if (!lis)
		return (-1);
	while (i < size)
	{
		if (max < lis[i])
			max = lis[i];
		i++;
	}
	return (max);
}
