void	sort_three(t_stack *a)
{
	int	*d;
	int	t;

	d = a->data;
	t = a->top;
	if (t == 1 && d[1] > d[0])
		sa(a, 1);
	if (t < 2)
		return ;
	if (d[t] > d[t - 1] && d[t - 1] < d[t - 2] && d[t] < d[t - 2])
		sa(a, 1);
	else if (d[t] > d[t - 1] && d[t - 1] > d[t - 2])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (d[t] > d[t - 1] && d[t - 1] < d[t - 2])
		ra(a, 1);
	else if (d[t] < d[t - 1] && d[t - 1] > d[t - 2] && d[t] < d[t - 2])
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (d[t] < d[t - 1] && d[t - 1] > d[t - 2])
		rra(a, 1);
}
