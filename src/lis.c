/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:02:17 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 21:35:37 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	lower_bound(long long *arr, long long n, long long x)
{
	long long	mid;
	long long	low;
	long long	high;

	high = n;
	low = 0;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (x <= arr[mid])
			high = mid;
		else
			low = mid + 1;
	}
	if (low < n && arr[low] < x)
		low++;
	return (low);
}

// Get LIS (Longest Increasing Subsequence) using dp
long long	*get_lis(t_stacks *stacks, long long *length)
{
	long long	idx;
	long long	*dp;

	dp = (long long *)ft_calloc(stacks->a.capacity, sizeof (long long));
	if (!dp)
		return (NULL);
	idx = 1;
	*length = 1;
	dp[0] = stacks->a.buffer[0];
	while (idx < stacks->a.capacity)
	{
		if (dp[*length - 1] < stacks->a.buffer[idx])
			dp[(*length)++] = stacks->a.buffer[idx];
		else
		{
			dp[lower_bound(stacks->a.buffer, *length,
				stacks->a.buffer[idx])] = stacks->a.buffer[idx];
		}
		idx++;
	}
	return (dp);
}
