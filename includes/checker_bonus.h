/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:35:16 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/07 19:42:03 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 42

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	char	name;
	t_node	*head;
	t_node	*tail;
	t_node	*max;
	t_node	*min;
	int		size;
}	t_deque;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* checker_bonus.c */
void	extract_cmd(t_deque *a, t_deque *b);
void	is_ok(t_deque *a, t_deque *b);

/* check_n_parse_bonus.c */
int		check_argv(int ac, char **av, int *nums, int size);

/* deque_bonus.c, deque_utils_bonus.c */
t_deque	*init_deque(t_deque *dq, char name);
t_node	*get_new_node(int newData);
int		is_empty(t_deque *dq);
int		push_head(t_deque *dq, int newData);
int		push_tail(t_deque *dq, int newData);
int		pop_head(t_deque *dq);
int		pop_tail(t_deque *dq);
t_node	*get_max(t_deque *dq);
t_node	*get_min(t_deque *dq);
t_node	*get_n_th(t_deque *a, t_node *first, int index);
void	free_deque(t_deque *dq);

/* operations_bonus.c */
void	swap(t_deque *dq);
void	ss(t_deque *a, t_deque *b);
void	push(t_deque *from, t_deque *to);
void	rotate(t_deque *dq);
void	rr(t_deque *a, t_deque *b);
void	reverse_rotate(t_deque *dq);
void	rrr(t_deque *a, t_deque *b);

/* prepare_bonus.c */
int		prep_int_arr(char **str, int *nums, int part_size, int all_size);
int		prep_stacks(t_deque *a, t_deque *b, int *nums, int size);
t_node	*get_next_node(t_deque *a, t_node *cur);

/* manage_arr_bonus.c */
void	free_arr(int *arr);
void	free_double_char(char **arr, int size);
void	copy_arr(int *from, int **to, int size);
void	set_arr(int *arr, int set_num, int size);
int		is_exist(int *lis, int target, int lis_size);

/* ft_function_bonus.c */
int		ft_atoi(char *str, int *disc);
int		cnt_chars(char *str, char c);
char	**ft_split(char *s, char c, int *part_size);

#endif
