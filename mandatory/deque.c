/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:01:46 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:22:30 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (dq->max->data < new_node->data)
		dq->max = new_node;
	if (dq->min->data > new_node->data)
		dq->min = new_node;
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
	if (dq->max->data < new_node->data)
		dq->max = new_node;
	if (dq->min->data > new_node->data)
		dq->min = new_node;
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
	{
		dq->head = NULL;
	}
	else
	{
		dq->tail->next = NULL;
	}
	free(tmp);
	dq->max = get_max(dq);
	dq->min = get_min(dq);
	dq->size--;
	return (target);
}
