/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:25:24 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/05 16:25:27 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Adds and int to the top of the stack, returns 1 if it succeeded
int	push(t_stack *stack, int value)
{
	if (is_stack_full(stack))
		return (-1);
	stack->arr[++stack->top] = value;
	return (1);
}

// Pop an element from the stack and returns it
int	pop(t_stack *stack)
{
	int	popped;

	if (is_stack_empty(stack))
		return (-1);
	popped = stack->arr[stack->top];
	stack->arr[stack->top--] = 0;
	return (popped);
}

// Returns the top element of the stack 
int	peek(t_stack *stack)
{
	if (is_stack_empty(stack))
		return (-1);
	return (stack->arr[stack->top]);
}

// Checks if the stack is full
int	is_stack_full(t_stack *stack)
{
	if (stack->top >= stack->size)
		return (1);
	else
		return (0);
}

// Checks if the stack is empty
int	is_stack_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	else
		return (0);
}

/*
ft_printf("Stack Overflow\n");
ft_printf("Pushed %d onto the stack\n", value);
ft_printf("Stack Underflow\n");
ft_printf("Popped %d from the stack\n", popped);
ft_printf("Stack is empty\n");
*/