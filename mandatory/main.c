/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:12:43 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:28:35 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	int		*nums;
	int		size;

	if (ac < 2)
		return (0);
	if (ac == 2)
		size = cnt_chars(av[1], ' ');
	else
		size = ac - 1;
	nums = malloc(sizeof(int) * size);
	if (!nums)
		return (0);
	check_argv(ac, av, nums, size);
	if (prep_stacks(&a, &b, nums, size) == FALSE)
		return (1);
	free_arr(nums);
	push_swap(&a, &b);
	free_deque(&a);
	free_deque(&b);
	return (0);
}
