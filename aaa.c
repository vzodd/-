int	get_chunk_size(int total_size)
{
	if (total_size <= 16)
		return (3);
	if (total_size <= 100)
		return (15);
	return (35);
}
void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = get_chunk_size(a->size);
	while (a->top >= 0)
	{
		if (a->data[a->top] <= i)
		{
			pb(a, b, 1);
			i++;
		}
		else if (a->data[a->top] <= i + chunk_size)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}
int	find_max_pos(t_stack *stack)
{
	int	max_val;
	int	max_pos;
	int	i;

	i = stack->top;
	max_val = stack->data[i];
	max_pos = i;
	while (i >= 0)
	{
		if (stack->data[i] > max_val)
		{
			max_val = stack->data[i];
			max_pos = i;
		}
		i--;
	}
	return (max_pos);
}
void	push_max_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	steps;

	max_pos = find_max_pos(b);
	steps = b->top - max_pos;
	if (steps <= b->top / 2)
	{
		while (steps > 0)
		{
			rb(b, 1);
			steps--;
		}
	}
	else
	{
		while (max_pos >= 0)
		{
			rrb(b, 1);
			max_pos--;
		}
	}
	pa(a, b, 1);
}
void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_chunks_to_b(stack_a, stack_b);
	while (stack_b->top >= 0)
	{
		push_max_to_a(stack_a, stack_b);
	}
}
