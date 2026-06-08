/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:05:57 by alvespin          #+#    #+#             */
/*   Updated: 2026/06/02 10:53:24 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Bench stats definition

typedef struct stats
{
	int		display;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_stats;

// Stack definition

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		top;
	t_stats	stats;
}			t_stack;

// Stack functions

int			push(t_stack *stack, int value);
int			pop(t_stack *stack);
int			peek(t_stack *stack);
int			is_stack_empty(t_stack *stack);
int			is_stack_full(t_stack *stack);
void		init_stack(t_stack *stack, int size);
void		free_stack(t_stack *stack);
void		print_stacks(t_stack *a, t_stack *b);
void		normalize_stack(t_stack *a);

// Bench stats functions

void		init_stats(t_stats *stats);
void		activate_stats(t_stats *stats);
int			is_active(t_stats *stats);
void		stats_count(int *counter, t_stats *stats, const char *op_name);
int			total_ops(t_stats *stats);
void		print_results(t_stats *stats, int mode, float disorder);

// Stack manipulation functions

void		sa(t_stack *a);
void		sb(t_stack *a, t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);

// Sorting strategies functions

int			compute_disorder(t_stack *a);
void		sort_simple(t_stack *a, t_stack *b);
void		sort_medium(t_stack *a, t_stack *b);
void		sort_complex(t_stack *a, t_stack *b);
void		sort_adaptive(t_stack *a, t_stack *b, float *disoder);

// Additional functions

int			ft_printf(char const *s, ...);
int			ft_putchar(char c);
int			ft_putfloat(float f);
void		ft_exit(char *str);

// Input processing functions

int			ft_strncmp(char const *s1, char const *s2, size_t n);
int			*parse_nums(int argc, char **argv, int start, int *size);
char		*ft_strchr(char const *s, int c);
int			check_num_arr(int *num_arr, int size);
int			ft_atoi(char const *s);
int			ft_is_int(char *str);
char		**ft_split(char const *s, int size, int c);

#endif
