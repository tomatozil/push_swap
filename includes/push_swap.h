/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:54:07 by jiyun             #+#    #+#             */
/*   Updated: 2022/11/08 21:54:12 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

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

void	push_swap(t_deque *a, t_deque *b);

/* check_n_parse.c */
int		check_argv(int ac, char **av, int *nums, int size);

/* deque.c, deque_utils.c deque_life_death.c */
t_deque	*init_deque(t_deque *dq, char name);
t_node	*get_new_node(int new_data);
int		is_empty(t_deque *dq);
int		push_head(t_deque *dq, int new_data);
int		push_tail(t_deque *dq, int new_data);
int		pop_head(t_deque *dq);
int		pop_tail(t_deque *dq);
void	update_min_max(t_deque *dq, t_node *node);
t_node	*get_max(t_deque *dq);
t_node	*get_min(t_deque *dq);
t_node	*get_n_th(t_deque *a, t_node *first, int index);
void	free_deque(t_deque *dq);

/* operations.c */
void	swap(t_deque *dq);
void	ss(t_deque *a, t_deque *b);
void	push(t_deque *from, t_deque *to);
void	rotate(t_deque *dq);
void	rr(t_deque *a, t_deque *b);
void	reverse_rotate(t_deque *dq);
void	rrr(t_deque *a, t_deque *b);

/* prepare.c */
int		prep_int_arr(char **str, int *nums, int part_size, int all_size);
int		prep_stacks(t_deque *a, t_deque *b, int *nums, int size);
t_node	*get_next_node(t_deque *a, t_node *cur);

/* manage_arr.c */
void	free_arr(int *arr);
void	free_double_char(char **arr, int size);
void	copy_arr(int *from, int **to, int size);
void	set_arr(int *arr, int set_num, int size);
int		is_exist(int *lis, int target, int lis_size);

/* ft_function.c */
int		ft_atoi(char *str, int *disc);
int		cnt_chars(char *str, char c);
char	**ft_split(char *s, char c, int *part_size);

/* lis.c */
void	remain_lis(t_deque *a, t_deque *b);

/* lis_utils.c */
int		where_to_put(int *tmp, t_node *cur, int size);
int		get_max_in_lis(int *lis, int size);

/* move_cost.c */
void	move_to_top(t_deque *dq, int how_high);
void	move_together(t_deque *a, t_deque *b, int *costs);
int		get_how_high(t_deque *dq, t_node *target);
t_node	*get_least_cost(t_deque *me, t_deque *another, int *costs);

/* move_cost_utils.c */
long	ft_abs(long num);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		calc_together(int a, int b);
t_node	*get_next_bigger(t_deque *another, int me);

/* sort.c */
int		is_deque_sorted(t_deque *a);
void	sort_two(t_deque *a);
void	sort_three(t_deque *a);
void	sort_four_five(t_deque *a, t_deque *b);
void	sort_big(t_deque *a, t_deque *b);

#endif
