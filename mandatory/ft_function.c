/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:10:13 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 19:27:01 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *disc)
{
	int		cnt;
	int		sign;
	int		ret;

	cnt = 0;
	sign = 1;
	ret = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || \
			*str == '\n' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		cnt++;
		str++;
	}
	if (*str != '\0' || cnt > 10 || \
			ret * sign > 2147483647 || ret * sign < -2147483648)
		*disc = FALSE;
	return (ret * sign);
}

static int	put_str(char **ret, char *cur, int size, int i)
{
	int	j;

	ret[i] = malloc(sizeof(char) * (size + 1));
	if (ret[i] == 0)
		return (FALSE);
	j = 0;
	while (j < size)
	{
		ret[i][j] = cur[j];
		j++;
	}
	ret[i][j] = '\0';
	return (TRUE);
}

int	cnt_chars(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			cnt++;
			while (*str != '\0' && *str != c)
				str++;
			str--;
		}
		str++;
	}
	return (cnt);
}

char	**malloc_chars(char *chars, char c, int *size)
{
	char	**ret;

	if (!chars)
		return (0);
	*size = cnt_chars(chars, c);
	ret = malloc(sizeof(char *) * (*size + 1));
	if (ret == 0)
		return (0);
	return (ret);
}

char	**ft_split(char *s, char c, int *part_size)
{
	char	**ret;
	int		cnt;
	int		i;

	ret = malloc_chars(s, c, part_size);
	if (ret == 0)
		return (0);
	cnt = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i = 0;
			while (*(s + i) != '\0' && *(s + i) != c)
				i++;
			if (put_str(ret, s, i, cnt++) == FALSE)
				return (0);
			s += i - 1;
		}
		s++;
	}
	ret[*part_size] = 0;
	return (ret);
}
