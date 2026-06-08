int	find_min_position(t_stack *stack)
{
	int		min_val;
	int		min_pos;
	int		current_pos;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	min_val = tmp->value;
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = current_pos;
		}
		current_pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(*stack_a);
	size = stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a, 1);
			min_pos++;
		}
	}
	pb(stack_a, stack_b, 1);
}
void	sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 5)
		push_min_to_b(stack_a, stack_b);
	if (size >= 4)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
int	stack_size(t_stack *stack)
{
    int	i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}
