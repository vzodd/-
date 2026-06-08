void	sort_three(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	if (stack_a->top < 2)
	{
		if (stack_a->top == 1 && stack_a->data[1] > stack_a->data[0])
			sa(stack_a, 1);
		return ;
	}
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
