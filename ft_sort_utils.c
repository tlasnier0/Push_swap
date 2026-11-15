#include "ft_push_swap.h"

size_t	find_min_pos(const t_stack *s)
{
	size_t	i;
	size_t	pos;

	pos = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->data[i].value < s->data[pos].value)
			pos = i;
		i++;
	}
	return (pos);
}

size_t	find_max_pos(const t_stack *s)
{
	size_t	i;
	size_t	pos;

	pos = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->data[i].value > s->data[pos].value)
			pos = i;
		i++;
	}
	return (pos);
}

int	is_sorted(const t_stack *s)
{
	size_t	i;

	i = 1;
	while (i < s->size)
	{
		if (s->data[i - 1].value > s->data[i].value)
			return (0);
		i++;
	}
	return (1);
}

void	rotate_a_to(t_ctx *ctx, size_t pos)
{
	size_t	i;

	if (pos <= ctx->a.size - pos)
	{
		i = 0;
		while (i++ < pos)
			ra(ctx);
	}
	else
	{
		i = pos;
		while (i++ < ctx->a.size)
			rra(ctx);
	}
}

void	rotate_b_to(t_ctx *ctx, size_t pos)
{
	size_t	i;

	if (pos <= ctx->b.size - pos)
	{
		i = 0;
		while (i++ < pos)
			rb(ctx);
	}
	else
	{
		i = pos;
		while (i++ < ctx->b.size)
			rrb(ctx);
	}
}
