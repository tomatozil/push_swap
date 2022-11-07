/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:01:46 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:17:59 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int newData)
{
	t_node  *newNode;

	newNode = malloc(sizeof(t_node));
	if (newNode == NULL)
		return (NULL);
	newNode->data = newData;
	newNode->prev = newNode->next = NULL;

	return (newNode);
}

int	push_head(t_deque *dq, int newData)
{
	t_node	*newNode;

	newNode = get_new_node(newData);
	if (newNode == NULL)
		return (FALSE);
	if (is_empty(dq))
	{
		dq->head = dq->tail = dq->min = dq->max = newNode;
		dq->tail->next = NULL;
	}
	else
	{
		newNode->next = dq->head;
		dq->head->prev = newNode;
		dq->head = newNode;
	}
	dq->head->prev = NULL;
	if (dq->max->data < newNode->data)
		dq->max = newNode;
	if (dq->min->data > newNode->data)
		dq->min = newNode;
	dq->size++;
	return (TRUE);
}

int	push_tail(t_deque *dq, int newData)
{
	t_node	*newNode;

	newNode = get_new_node(newData);
	if (newNode == NULL)
		return (FALSE);
	if (is_empty(dq))
	{
		dq->head = dq->tail = dq->min = dq->max = newNode;
		dq->head->prev = NULL;
	}
	else
	{
		newNode->prev = dq->tail;
		dq->tail->next = newNode;
		dq->tail = newNode;
	}
	dq->tail->next = NULL;
	if (dq->max->data < newNode->data)
		dq->max = newNode;
	if (dq->min->data > newNode->data)
		dq->min = newNode;
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
	} else
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
	t_node  *tmp;

	target = dq->tail->data;
	tmp = dq->tail;
	dq->tail = dq->tail->prev;
	if (dq->tail == NULL)
	{
		dq->head = NULL;
	} else
	{
		dq->tail->next = NULL;
	}
	free(tmp);
	dq->max = get_max(dq);
	dq->min = get_min(dq);
	dq->size--;
	return (target);
}
