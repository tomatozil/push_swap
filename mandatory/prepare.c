/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:15:37 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:38 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prep_int_arr(char **str, int *nums, int part_size, int filled_size)
{
	int	value;
	int	i;
	int	disc;
	int	current_start;

	i = 0;
	disc = TRUE;
	current_start = filled_size - part_size;
	while (i + current_start < filled_size)
	{
		value = ft_atoi(str[i], &disc);
		if (disc == FALSE)
			return (FALSE);
		nums[i + current_start] = value;
		i++;
	}
	return (TRUE);
}

int	prep_stacks(t_deque *a, t_deque *b, int *nums, int size)
{
	int	i;

	i = 0;
	init_deque(a, 'a');
	while (i < size)
	{
		if (push_tail(a, nums[i]) == FALSE)
		{
			free_deque(a);
			return (FALSE);
		}
		i++;
	}
	init_deque(b, 'b');
	return (TRUE);
}

t_node	*get_next_node(t_deque *a, t_node *cur)
{
	if (cur->next == NULL)
		cur = a->head;
	else
		cur = cur->next;
	return (cur);
}
