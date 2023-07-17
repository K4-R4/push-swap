/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:05:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 14:07:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	long long	sz;

	sz = stacks->a.sz;
	if (sz == 2)
		sort_2(stacks, 'a');
	else if (sz == 3)
		sort_3(stacks, 'a');
	else if (sz == 4)
		sort_4(stacks, 'a');
	else if (sz == 5)
		sort_5(stacks, 'a');
}
