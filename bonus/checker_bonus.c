/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:25:29 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:38:39 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (0);
	while (*s1 != '\0' && *(unsigned char *)s1 == *(unsigned char *)s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

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

void	do_cmd(char *cmd, t_deque *a, t_deque *b)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b);
	else
		error_exit();
}

void	is_ok(t_deque *a, t_deque *b)
{
	if (is_deque_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 6);
}

void	extract_cmd(t_deque *a, t_deque *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		do_cmd(cmd, a, b);
		cmd = get_next_line(0);
	}
}
