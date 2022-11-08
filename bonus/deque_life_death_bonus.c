#include "checker_bonus.c"

t_deque	*init_deque(t_deque *dq, char name)
{
	dq->name = name;
	dq->head = NULL;
	dq->tail = NULL;
	dq->max = NULL;
	dq->min = NULL;
	dq->size = 0;
	return (dq);
}

void	free_deque(t_deque *dq)
{
	int		i;
	t_node	*cur;
	t_node	*tmp;

	i = 0;
	if (is_empty(dq))
		return ;
	cur = dq->head;
	while (i < dq->size)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
		i++;
	}
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
