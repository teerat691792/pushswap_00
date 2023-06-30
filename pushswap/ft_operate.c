
#include "libpushswap.h"

//swap last 2 nodes of stack_a |OR| do nothing if there is only one or NO
//swap last 2 nodes of stack_b |OR| do nothing if there is only one or NO
// do sa && sb , ss

//take last node of stack_b to last node of stack_a |OR| do nothing if stack_b is empty, pa
//take last node of stack_a to last node of stack_b |OR| do nothing if stack_a is empty, pb

//take last node of stack_a to first node of stack_a
void	ft_ra(t_node **root)
{
	t_node	*curr;
	int value;

	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	value = curr->value;
	ft_nodeaddfront(*root, value);

}
//take last node of stack_b to first node of stack_b
//do ra & rb , rr

//take first node of stack_a to last node of stack_a
//take first node of stack_b to last node of stack_b
///do rra & rrb , rrr

