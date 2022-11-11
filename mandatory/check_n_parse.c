/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:01:02 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:07:52 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	check_argv(int ac, char **av, int *nums, int size)
{
	char	**chars;
	int		part_size;
	int		filled_size;
	int		i;

	i = 1;
	filled_size = 0;
	while (i < ac)
	{
		part_size = 0;
		chars = ft_split(av[i], ' ', &part_size);
		if (!chars || (ac != 2 && part_size != 1))
			error_exit(chars, NULL);
		filled_size += part_size;
		if (prep_int_arr(chars, nums, part_size, filled_size) == FALSE)
			error_exit(chars, nums);
		free_double_char(chars);
		i++;
	}
	if (check_duplicate(nums, size) == FALSE)
		error_exit(NULL, nums);
}
