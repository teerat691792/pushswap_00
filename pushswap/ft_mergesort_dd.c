
#include "libpushswap.h"

void	ft_startsort_dd(t_merge *merge, int lf, int rg)
{
	int	mid;

	if (lf < rg)
	{
		mid = (lf + rg) / 2;
		ft_startsort_dd(merge, lf, mid);
		ft_startsort_dd(merge, mid + 1, rg);
		ft_mergearr_dd(merge, lf, mid, rg);
	}
}

void	ft_mergearr_dd(t_merge *merge, int lf, int mid, int rg)
{
	merge->tmp_lf = malloc(sizeof(int) * (mid - lf + 1));
	merge->tmp_rg = malloc(sizeof(int) * (rg - mid));
	if (!merge->tmp_lf || !merge->tmp_rg)
		return ;
	ft_copyarr_dd(merge->tmp_lf, merge->arr, lf, (mid - lf + 1));
	ft_copyarr_dd(merge->tmp_rg, merge->arr, mid + 1, (rg - mid));
	ft_mergeoption(merge, lf, mid, rg);
	free (merge->tmp_lf);
	free (merge->tmp_rg);
}

void	ft_mergeoption(t_merge *merge, int lf, int mid, int rg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = lf;
	while (k <= rg)
	{
		if (i < (mid - lf + 1) && j >= (rg - mid))
			ft_mergeput_dd(merge->arr, merge->tmp_lf, &k, &i);
		else if (i >= (mid - lf + 1) && j < (rg - mid))
			ft_mergeput_dd(merge->arr, merge->tmp_rg, &k, &j);
		else if (merge->tmp_lf[i] <= merge->tmp_rg[j])
			ft_mergeput_dd(merge->arr, merge->tmp_lf, &k, &i);
		else
			ft_mergeput_dd(merge->arr, merge->tmp_rg, &k, &j);
	}
}

void	ft_copyarr_dd(int *dst, int *src, int index, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[index + i];
		i++;
	}
}

void	ft_mergeput_dd(int *arr, int *tmp, int *k, int *index)
{
	arr[*k] = tmp[*index];
	*k = *k + 1;
	*index = *index + 1;
}
