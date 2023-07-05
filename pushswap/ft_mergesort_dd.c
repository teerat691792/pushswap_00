
#include "libpushswap.h"

void ft_mergesort_dd(int *arr, int len)
{
	ft_startsort_dd(arr, 0, len - 1);
}

void	ft_startsort_dd(int *arr, int lf, int rg)
{
	int mid;

	if (lf < rg)
	{
		mid = (lf + rg) / 2;
		ft_startsort_dd(arr, lf, mid);
		ft_startsort_dd(arr, mid + 1, rg);
		ft_mergearr_dd(arr, lf, mid, rg);
	}
}

void	ft_mergearr_dd(int *arr,int lf, int mid, int rg)
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
	ft_copyarr_dd(tmp_lf, arr, lf, (mid - lf + 1));
	ft_copyarr_dd(tmp_rg, arr, mid + 1, (rg - mid));
	i = 0;
	j = 0;
	k = lf;
	while (k <= rg)
	{
		if (i < (mid - lf + 1) && j >= (rg - mid))
			ft_mergeput_dd(arr, tmp_lf, &k, &i);
		else if (i >= (mid - lf + 1) && j < (rg - mid))
			ft_mergeput_dd(arr, tmp_rg, &k, &j);
		else if (tmp_lf[i] <= tmp_rg[j])
			ft_mergeput_dd(arr, tmp_lf, &k, &i);
		else
			ft_mergeput_dd(arr, tmp_rg, &k, &j);
	}
	free(tmp_lf);
	free(tmp_rg);
}

void	ft_mergeput_dd(int *arr, int *tmp, int *k, int *index)
{
	arr[*k] = tmp[*index];
	*k = *k + 1;
	*index = *index + 1;
}

void	ft_copyarr_dd(int *dst, int *src, int index, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[index + i];
		i++;
	}
}
