/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:15:22 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:15:33 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deque *dq)
{
	push_tail(dq, pop_head(dq));
	write(1, "r", 1);
	write(1, &dq->name, 1);
	write(1, "\n", 1);
}

void	rr(t_deque *a, t_deque *b)
{
	push_tail(a, pop_head(a));
	push_tail(b, pop_head(b));
	write(1, "rr", 2);
	write(1, "\n", 1);
}

void	reverse_rotate(t_deque *dq)
{
	push_head(dq, pop_tail(dq));
	write(1, "rr", 2);
	write(1, &dq->name, 1);
	write(1, "\n", 1);
}

void    rrr(t_deque *a, t_deque *b)
{
	push_head(a, pop_tail(a));
	push_head(b, pop_tail(b));
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
