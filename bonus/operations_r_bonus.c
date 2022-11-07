/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:33:48 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:34:06 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate(t_deque *dq)
{
	push_tail(dq, pop_head(dq));
}

void	rr(t_deque *a, t_deque *b)
{
	push_tail(a, pop_head(a));
	push_tail(b, pop_head(b));
}

void	reverse_rotate(t_deque *dq)
{
	push_head(dq, pop_tail(dq));
}

void	rrr(t_deque *a, t_deque *b)
{
	push_head(a, pop_tail(a));
	push_head(b, pop_tail(b));
}
