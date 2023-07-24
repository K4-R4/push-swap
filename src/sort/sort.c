/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:05:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/23 18:32:49 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	long long	sz;

	sz = stacks->a.sz;
	if (sz == 2)
		sort_2(stacks, true);
	else if (sz == 3)
		sort_3_a(stacks);
	else if (sz == 4)
		sort_4_a(stacks);
	else if (sz == 5)
		sort_5_a(stacks);
	else
		sort_many(stacks);
}
