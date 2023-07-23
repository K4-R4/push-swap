/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:15:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 20:47:54 by tkuramot         ###   ########.fr       */
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
	char		*instructions;
}				t_stacks;

void	stack_sa(t_stacks *stacks);
void	stack_sb(t_stacks *stacks);
void	stack_ss(t_stacks *stacks);
void	stack_pa(t_stacks *stacks);
void	stack_pb(t_stacks *stacks);
void	stack_ra(t_stacks *stacks);
void	stack_rb(t_stacks *stacks);
void	stack_rr(t_stacks *stacks);
void	stack_rra(t_stacks *stacks);
void	stack_rrb(t_stacks *stacks);
void	stack_rrr(t_stacks *stacks);
void	stack_save_instr(t_stacks *stacks, char *instruction);

#endif
