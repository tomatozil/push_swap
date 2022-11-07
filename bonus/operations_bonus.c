/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:33:19 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:33:44 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_deque *dq)
{
	int	first;
	int	second;

	first = pop_head(dq);
	second = pop_head(dq);
	push_head(dq, first);
	push_head(dq, second);
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
}

void	push(t_deque *from, t_deque *to)
{
	push_head(to, pop_head(from));
}
