
#include "libpushswap.h"

void	ft_printstack_dd(t_node *stack)
{
	t_node	*curr;

	if (!stack)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	curr = stack;
	while (curr != NULL)
	{
		ft_printf(" %d\t",curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	ft_showstack_dd(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a : ");
	ft_printstack_dd(stack->tail_a);
	ft_printf("stack_b : ");
	ft_printstack_dd(stack->tail_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}

void	ft_printindex_dd(t_node *stack)
{
	t_node	*curr;

	if (!stack)
	{
		ft_printf("[NULL]\n");
		return ;
	}
	curr = stack;
	while (curr != NULL)
	{
		ft_printf("[%d]\t",curr->index);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	ft_showindex_dd(t_stack *stack)
{
	ft_printf("*****************************************************************\n");
	ft_printf("stack_a :\t");
	ft_printstack_dd(stack->tail_a);
	ft_printf("index_a :\t");
	ft_printindex_dd(stack->tail_a);
	ft_printf("\n");
	ft_printf("stack_b :\t");
	ft_printstack_dd(stack->tail_b);
	ft_printf("index_b :\t");
	ft_printindex_dd(stack->tail_b);
	ft_printf("*****************************************************************\n");
	ft_printf("\n");
}

void	ft_showvertical_dd(t_stack *stack)
{
	t_node	*curr_a;
	t_node	*curr_b;

	if (!stack)
	{
		ft_printf("(NULL)  STACK\n");
		return ;
	}
	curr_a = stack->head_a;
	curr_b = stack->head_b;
	ft_printf("{A}\t{B}\n");
	ft_printf("____\t____\n");
	if (curr_b == NULL)
	{
		ft_printf("[%d]\tNULL\n", curr_a->index);
		curr_a = curr_a->prev;
		while (curr_a != NULL)
		{
			ft_printf("[%d]\n", curr_a->index);
			curr_a = curr_a->prev;
		}
	}
	else if (curr_a == NULL)
	{
		ft_printf("NULL\t[%d]\n", curr_b->index);
		curr_b = curr_b->prev;
		while (curr_b != NULL)
		{
			ft_printf("   \t[%d]\n", curr_b->index);
			curr_b = curr_b->prev;
		}
	}
	else
	{
		while (curr_a != NULL || curr_b != NULL)
		{
			if (curr_a != NULL && curr_b == NULL)
			{
				ft_printf("[%d]\n", curr_a->index);
				curr_a = curr_a->prev;
			}
			else if (curr_a == NULL && curr_b != NULL)
			{
				ft_printf("   \t[%d]\n", curr_b->index);
				curr_b = curr_b->prev;
			}
			else
			{
				ft_printf("[%d]\t[%d]\n", curr_a->index, curr_b->index);
				curr_a = curr_a->prev;
				curr_b = curr_b->prev;
			}
		}
	}
}
