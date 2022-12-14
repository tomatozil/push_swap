/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:26:41 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:42:21 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_node	*get_new_node(int new_data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

int	push_head(t_deque *dq, int new_data)
{
	t_node	*new_node;

	new_node = get_new_node(new_data);
	if (new_node == NULL)
		return (FALSE);
	if (is_empty(dq))
	{
		dq->head = new_node;
		dq->tail = new_node;
		dq->min = new_node;
		dq->max = new_node;
		dq->tail->next = NULL;
	}
	else
	{
		new_node->next = dq->head;
		dq->head->prev = new_node;
		dq->head = new_node;
	}
	dq->head->prev = NULL;
	update_min_max(dq, new_node);
	dq->size++;
	return (TRUE);
}

int	push_tail(t_deque *dq, int new_data)
{
	t_node	*new_node;

	new_node = get_new_node(new_data);
	if (new_node == NULL)
		return (FALSE);
	if (is_empty(dq))
	{
		dq->head = new_node;
		dq->tail = new_node;
		dq->min = new_node;
		dq->max = new_node;
		dq->head->prev = NULL;
	}
	else
	{
		new_node->prev = dq->tail;
		dq->tail->next = new_node;
		dq->tail = new_node;
	}
	dq->tail->next = NULL;
	update_min_max(dq, new_node);
	dq->size++;
	return (TRUE);
}

int	pop_head(t_deque *dq)
{
	int		target;
	t_node	*tmp;

	target = dq->head->data;
	tmp = dq->head;
	dq->head = dq->head->next;
	if (dq->head == NULL)
	{
		dq->tail = NULL;
	}
	else
	{
		dq->head->prev = NULL;
	}
	free(tmp);
	dq->max = get_max(dq);
	dq->min = get_min(dq);
	dq->size--;
	return (target);
}

int	pop_tail(t_deque *dq)
{
	int		target;
	t_node	*tmp;

	target = dq->tail->data;
	tmp = dq->tail;
	dq->tail = dq->tail->prev;
	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->next = NULL;
	free(tmp);
	dq->max = get_max(dq);
	dq->min = get_min(dq);
	dq->size--;
	return (target);
}
