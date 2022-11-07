/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:15:01 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:15:18 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *dq)
{
	int	first;
	int	second;

	first = pop_head(dq);
	second = pop_head(dq);
	push_head(dq, first);
	push_head(dq, second);
	write(1, "s", 1);
	write(1, &dq->name, 1);
	write(1, "\n", 1);
}

void	ss(t_deque *a, t_deque *b)
{
	int	first;
	int	second;

	first = pop_head(a);
	second = pop_head(a);
	push_head(a, first);
	push_head(a, second);
	first = pop_head(b);
	second = pop_head(b);
	push_head(b, first);
	push_head(b, second);
	write(1, "ss", 2);
	write(1, "\n", 1);
}

void	push(t_deque *from, t_deque *to)
{
	push_head(to, pop_head(from));
	write(1, "p", 1);
	write(1, &to->name, 1);
	write(1, "\n", 1);
}
