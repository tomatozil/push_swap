/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:27:21 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:27:33 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_deque	*init_deque(t_deque *dq, char name)
{
	dq->name = name;
	dq->head = dq->tail = dq->max = dq->min = NULL;
	dq->size = 0;
	return (dq);
}

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
	t_node *max;
	t_node *cur;

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
	t_node *cur;
	int i;

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
