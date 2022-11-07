/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:13:32 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:14:20 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_deque *dq, int how_high)
{
	int	i;

	i = 0;
	if (how_high < 0)
	{
		how_high *= -1;
		while (i < how_high)
		{
			reverse_rotate(dq);
			i++;
		}
	}
	else
	{
		while (i < how_high)
		{
			rotate(dq);
			i++;
		}
	}
}

void	move_together(t_deque *a, t_deque *b, int *costs)
{
	int	together;
	int	tmp;

	together = calc_together(costs[0], costs[1]);
	tmp = together;
	if (costs[0] > 0)
	{
		while (tmp--)
			rr(a, b);
		move_to_top(a, costs[0] - together);
		move_to_top(b, costs[1] - together);
	}
	else
	{
		while (tmp--)
			rrr(a, b);
		move_to_top(a, costs[0] + together);
		move_to_top(b, costs[1] +  together);
	}
}

int	get_how_high(t_deque *dq, t_node *target)
{
	int		cnt;
	t_node	*cur;

	cnt = 0;
	cur = dq->head;
	while (cur != NULL && cur->data != target->data)
	{
		cnt++;
		cur = cur->next;
	}
	if (cnt <= (dq->size) / 2)
		return (cnt);
	else
		return (-(dq->size - cnt));
}

int	get_total_cost(int a, int b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(a);
	abs_b = ft_abs(b);

	if (a * b <= 0) // sign is different
		return (abs_a + abs_b);
	else
	if (abs_a > abs_b)
		return (abs_a);
	else
		return (abs_b);
}

t_node	*get_least_cost(t_deque *me, t_deque *another, int *costs)
{
	t_node	*least_cost;
	t_node	*cur;
	t_node	*next_bigger;
	int		total_cost;
	int		min;

	cur = me->head;
	min = me->size + another->size;
	while (cur != NULL)
	{
		next_bigger = get_next_bigger(another, cur->data);
		costs[0] = get_how_high(another, next_bigger);
		costs[1] = get_how_high(me, cur);
		total_cost = get_total_cost(costs[0], costs[1]);
		if (min > total_cost)
		{
			min = total_cost;
			least_cost = cur;
		}
		cur = cur->next;
	}
	return (least_cost);
}
