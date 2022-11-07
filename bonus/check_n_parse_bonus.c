/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_parse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:24:40 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:25:20 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	check_argv(int ac, char **av, int *nums, int size)
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
			return (FALSE);
		filled_size += part_size;
		if (prep_int_arr(chars, nums, part_size, filled_size) == FALSE)
			return (FALSE);
		free_double_char(chars, part_size);
		i++;
	}
	if (check_duplicate(nums, size) == FALSE)
		return (FALSE);
	return (TRUE);
}
