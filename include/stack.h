/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:15:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/16 18:50:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "deque.h"

typedef struct s_stacks
{
	t_deque a;
	t_deque b;
}				t_stacks;

void	stack_swap(t_stacks *stacks, char sta);
void	stack_ss(t_stacks *stacks);
void	stack_push(t_stacks *stacks, char sta);
void	stack_rotate(t_stacks *stacks, char sta);
void	stack_rr(t_stacks *stacks);
void	stack_rrotate(t_stacks *stacks, char sta);
void	stack_rrr(t_stacks *stacks);

#endif
