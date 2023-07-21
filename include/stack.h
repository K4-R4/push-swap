/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:15:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 00:15:10 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "deque.h"

typedef struct s_stacks
{
	bool	flag_print;
	t_deque a;
	t_deque b;
	long long	*alpha;
	long long	*beta;
}				t_stacks;

void	stack_swap(t_stacks *stacks, char sta);
void	stack_ss(t_stacks *stacks);
void	stack_push(t_stacks *stacks, char sta);
void	stack_rotate(t_stacks *stacks, char sta);
void	stack_rr(t_stacks *stacks);
void	stack_rrotate(t_stacks *stacks, char sta);
void	stack_rrr(t_stacks *stacks);
long long	stack_get_at(t_stacks *stacks, char sta, long long idx);
long long	stack_get_min_value(t_stacks *stacks, char cur_sta, long long n);
long long	stack_get_min_idx(t_stacks *stacks, char cur_sta, long long n);

#endif
