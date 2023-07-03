
#include "libpushswap.h"

void	ft_merge_sort(int *arr, int len)
{
	ft_merge_rcs(arr, 0, len - 1);
}

void	ft_merge_rcs(int *arr, int lf, int rg)
{
	int mid;

	if (lf < rg)
	{
		mid = (lf + rg) / 2;
		ft_merge_rcs(arr, lf, mid);
		ft_merge_rcs(arr, mid + 1, rg);
		ft_merge_arr(arr, lf, mid, rg);
	}
}

void	ft_merge_arr(int *arr,int lf, int mid, int rg)
{
	int	*tmp_lf;
	int	*tmp_rg;
	int i;
	int j;
	int k;

	// len_lf = mid - lf + 1;
	// len_rg = rg - mid;
	tmp_lf = malloc(sizeof(int) * (mid - lf + 1));
	tmp_rg = malloc(sizeof(int) * (rg - mid));
	if (!tmp_lf || !tmp_rg)
		return ;
	ft_copyarr(tmp_lf, arr, lf, (mid - lf + 1));
	ft_copyarr(tmp_rg, arr, mid + 1, (rg - mid));
	i = 0;
	j = 0;
	k = lf;
	while (k <= rg)
	{
		if (i < (mid - lf + 1) && j >= (rg - mid))
			ft_merge_put(arr, tmp_lf, &k, &i);
		else if (i >= (mid - lf + 1) && j < (rg - mid))
			ft_merge_put(arr, tmp_rg, &k, &j);
		else if (tmp_lf[i] <= tmp_rg[j])
			ft_merge_put(arr, tmp_lf, &k, &i);
		else
			ft_merge_put(arr, tmp_rg, &k, &j);
	}
	free(tmp_lf);
	free(tmp_rg);
}

void	ft_merge_put(int *arr, int *tmp, int *k, int *index)
{
	arr[*k] = tmp[*index];
	*k = *k + 1;
	*index = *index + 1;
}


void	ft_copyarr(int *dst, int *src, int index, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[index + i];
		i++;
	}
}

void	ft_readarr(int *arr, int len)
{
	int i;

	i = 0;
	ft_printf("len = %d\n", len);
	ft_printf("arr =\t\t");
	while (i < len)
	{
		ft_printf("{%d}\t", arr[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_noderead(t_stack *stack)
{
	int len;
	int *arr;

	len = ft_nodecount_rcs(stack->root_a);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return ;
	ft_nodecopy(stack->root_a, arr);
	// ft_readarr(arr, len);
	ft_merge_sort(arr, len);
	ft_readarr(arr, len);
	ft_putindex(&stack->root_a, arr);
	free(arr);
}

void	ft_nodecopy(t_node *stack, int *arr)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

void	ft_putindex(void **root, int *arr)
{
	int i;
	t_node *curr;

	curr = *root;
	while (curr != NULL)
	{
		i = 0;
		while (arr[i] != curr->value)
			i++;
		curr->index = i;
		curr = curr->next;
	}
}
