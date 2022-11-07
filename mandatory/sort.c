/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:16:08 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:16:58 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_deque_sorted(t_deque *a)
{
	int		i;
	t_node	*first;
	t_node	*second;

	i = 0;
	first = a->head;
	while (i < (a->size) - 1)
	{
		second = first->next;
		if (first->data > second->data)
			return (FALSE);
		first = first->next;
		i++;
	}
	return (TRUE);
}

void	sort_two(t_deque *a)
{
	swap(a);
}

void	sort_three(t_deque *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->data;
	second = a->head->next->data;
	third = a->tail->data;

	if (first < third && third < second)
	{
		swap(a);
		rotate(a);
	}
	else if (second < first && first < third)
		swap(a);
	else if (third < first && first < second)
		reverse_rotate(a);
	else if (second < third && third < first)
		rotate(a);
	else if (third < second && second < first)
	{
		swap(a);
		reverse_rotate(a);
	}
}

void	sort_four_five(t_deque *a, t_deque *b)
{
	t_node	*cur;
	t_node	*next_bigger;
	int		how_high;

	while (a->size > 3)
		push(a,b);
	sort_three(a);
	cur = b->head;
	if (cur->data > a->tail->data || cur->data < a->head->data)
		push(b,a);
	while (b->size > 0)
	{
		next_bigger = get_next_bigger(a, cur->data);
		how_high = get_how_high(a, next_bigger);
		move_to_top(a, how_high);
		push(b,a);
	}
	move_to_top(a, get_how_high(a, a->min));
}

void	sort_big(t_deque *a, t_deque *b)
{
	t_node	*a_target;
	t_node	*b_target;
	int		costs[2];

	remain_lis(a, b);
	while (b->size > 0)
	{
		b_target = get_least_cost(b, a, costs);
		a_target = get_next_bigger(a, b_target->data);
		costs[0] = get_how_high(a, a_target);
		costs[1] = get_how_high(b, b_target);
		if (costs[0] * costs[1] < 0)
		{
			move_to_top(a, costs[0]);
			move_to_top(b, costs[1]);
		}
		else
			move_together(a, b, costs);
		push(b,a);
	}
	move_to_top(a, get_how_high(a, a->min));
}
