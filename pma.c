void	push_max_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	steps;

	max_pos = find_max_pos(b);
	if (b->top - max_pos <= b->top / 2)
	{
		steps = b->top - max_pos;
		while (steps > 0)
		{
			rb(b, 1);
			steps--;
		}
	}
	else
	{
		steps = max_pos + 1;
		while (steps > 0)
		{
			rrb(b, 1);
			steps--;
		}
	}
	pa(a, b, 1);
}
