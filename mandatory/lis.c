/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:10:31 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:27:27 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_each_lis(t_deque *a, t_node *cur)
{
	int	*lis;
	int	*tmp;
	int	i;

	lis = malloc(sizeof(int) * a->size);
	if (!lis)
		return (0);
	tmp = malloc(sizeof(int) * a->size);
	if (!tmp)
		return (0);
	set_arr(lis, -1, a->size);
	set_arr(tmp, -1, a->size);
	i = 0;
	while (i < a->size)
	{
		lis[i] = where_to_put(tmp, cur, a->size);
		cur = get_next_node(a, cur);
		i++;
	}
	free_arr(tmp);
	return (lis);
}

int	*converse_lis(t_deque *a, t_node *first, int *tmp, int size)
{
	int	*ret;
	int	idx;
	int	i;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	i = a->size - 1;
	idx = size - 1;
	while (i >= 0 || idx >= 0)
	{
		if (idx == tmp[i])
		{
			ret[idx] = (get_n_th(a, first, i))->data;
			idx--;
		}
		i--;
	}
	return (ret);
}

void	get_lis_idx_arr(t_deque *a, t_node **first, int **best, int *lis_size)
{
	t_node	*cur;
	int		*tmp;
	int		now_max;
	int		before_max;
	int		i;

	cur = a->head;
	before_max = -1;
	i = 0;
	while (i < a->size)
	{
		tmp = get_each_lis(a, cur);
		now_max = get_max_in_lis(tmp, a->size);
		if (now_max > before_max)
		{
			copy_arr(tmp, best, a->size);
			before_max = now_max;
			(*first) = cur;
			*lis_size = now_max + 1;
		}
		cur = get_next_node(a, cur);
		i++;
		free_arr(tmp);
	}
}

int	*get_best_lis(t_deque *a, int *lis_size)
{
	int		*best;
	int		*ret;
	t_node	*first;

	best = malloc(sizeof(int) * a->size);
	if (!best)
		return (0);
	get_lis_idx_arr(a, &first, &best, lis_size);
	ret = converse_lis(a, first, best, *lis_size);
	free_arr(best);
	return (ret);
}

void	remain_lis(t_deque *a, t_deque *b)
{
	int		*lis;
	int		lis_size;
	t_node	*head;
	int		cnt;

	lis = get_best_lis(a, &lis_size);
	cnt = a->size - lis_size;
	while (cnt)
	{
		head = a->head;
		if (is_exist(lis, head->data, lis_size) == TRUE)
			rotate(a);
		else
		{
			push(a, b);
			cnt--;
		}
	}
	free_arr(lis);
}
