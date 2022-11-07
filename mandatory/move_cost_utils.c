/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:14:28 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:14:55 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calc_together(int a, int b)
{
	int	together;

	together = 0;
	if (a > 0 && b > 0)
		together = ft_min(a, b);
	else if (a < 0 && b < 0)
		together = -ft_max(a, b);
	return (together);
}

t_node	*get_next_bigger(t_deque *another, int me)
{
	t_node	*tmp;
	t_node	*next_bigger;
	int		min_diff;

	tmp = another->head;
	next_bigger = tmp;
	min_diff = ft_abs(tmp->data - me);
	while (tmp != NULL)
	{
		if (min_diff > ft_abs(tmp->data - me))
		{
			next_bigger = tmp;
			min_diff = ft_abs(next_bigger->data - me);
		}
		tmp = tmp->next;
	}
	if (next_bigger->data < me)
		next_bigger = next_bigger->next;
	if (next_bigger == NULL)
		next_bigger = another->head;
	return (next_bigger);
}
