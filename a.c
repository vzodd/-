int	find_min_position(t_stack *stack)
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
void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;
	int	steps_to_top;

	min_pos = find_min_position(stack_a);
	steps_to_top = stack_a->top - min_pos;
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
		while (min_pos >= 0)
		{
			rra(stack_a, 1);
			min_pos--;
		}
	}
	pb(stack_a, stack_b, 1);
}
void	sort_medium(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == 4)
		push_min_to_b(stack_a, stack_b);
	if (stack_a->top >= 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->top >= 0)
		pa(stack_a, stack_b, 1);
}
void	sort_three(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_a->data[stack_a->top];
	mid = stack_a->data[stack_a->top - 1];
	bot = stack_a->data[stack_a->top - 2];
	if (top > mid && mid < bot && top < bot)
		sa(stack_a, 1);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack_a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack_a, 1);
}
