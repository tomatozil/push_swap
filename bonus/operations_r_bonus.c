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
	if (is_empty(dq))
		return ;
	push_tail(dq, pop_head(dq));
}

void	rr(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_deque *dq)
{
	if (is_empty(dq))
		return ;
	push_head(dq, pop_tail(dq));
}

void	rrr(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
