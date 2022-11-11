/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_life_death.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:54:37 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 21:54:41 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*init_deque(t_deque *dq, char name)
{
	dq->name = name;
	dq->head = NULL;
	dq->tail = NULL;
	dq->max = NULL;
	dq->min = NULL;
	dq->size = 0;
	return (dq);
}

void	free_deque(t_deque *dq)
{
	int		i;
	t_node	*cur;
	t_node	*tmp;

	i = 0;
	if (is_empty(dq))
		return ;
	cur = dq->head;
	while (i < dq->size)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
		i++;
	}
}

void	error_exit(char **chars, int *nums)
{
	if (chars != NULL)
		free_double_char(chars);
	if (nums != NULL)
		free(nums);
	write(2, "Error\n", 6);
	exit(1);
}
