/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:27:21 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 21:51:48 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_empty(t_deque *dq)
{
	return (dq->head == NULL);
}

t_node	*get_min(t_deque *dq)
{
	t_node	*min;
	t_node	*cur;

	if (dq->size == 1)
		return (dq->tail);
	min = dq->head;
	cur = dq->head->next;
	while (cur != NULL)
	{
		if (min->data > cur->data)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*get_max(t_deque *dq)
{
	t_node	*max;
	t_node	*cur;

	if (dq->size == 1)
		return (dq->head);
	max = dq->head;
	cur = dq->head->next;
	while (cur != NULL)
	{
		if (max->data < cur->data)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

t_node	*get_n_th(t_deque *a, t_node *first, int index)
{
	t_node	*cur;
	int		i;

	cur = first;
	i = 0;
	while (i < index)
	{
		if (cur->next == NULL)
			cur = a->head;
		else
			cur = cur->next;
		i++;
	}
	return (cur);
}

void	update_min_max(t_deque *dq, t_node *node)
{
	if (dq->max->data < node->data)
		dq->max = node;
	if (dq->min->data > node->data)
		dq->min = node;
}
