int	find_min_pos(t_stack *stack)
{
	int	min_val;
	int	min_pos;
	int	i;

	if (stack->top < 0)
		return (-1);
	i = stack->top;
	min_val = stack->data[i];
	min_pos = i;
	while (i >= 0)
	{
		if (stack->data[i] < min_val)
		{
			min_val = stack->data[i];
			min_pos = i;
		}
		i--;
	}
	return (min_pos);
}
void	bring_to_top(t_stack *stack_a, int target_pos)
{
	int	steps_to_top;

	steps_to_top = stack_a->top - target_pos;
	if (steps_to_top <= stack_a->top / 2)
	{
		while (steps_to_top > 0)
		{
			ra(stack_a, 1);
			steps_to_top--;
		}
	}
	else
	{
		while (target_pos >= 0)
		{
			rra(stack_a, 1);
			target_pos--;
		}
	}
}
void	sort_indefinite(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	if (stack_a->top < 1)
		return ;
	while (stack_a->top > 2)
	{
		min_pos = find_min_pos(stack_a);
		bring_to_top(stack_a, min_pos);
		pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	while (stack_b->top >= 0)
		pa(stack_a, stack_b, 1);
}
