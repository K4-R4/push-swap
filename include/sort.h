/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:07:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 09:58:42 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
#define PUSH_H

#include "stack.h"

void	sort_small_2(t_stacks *stacks, char cur_sta);
void	sort_small_3(t_stacks *stacks, char cur_sta);
void	sort_small_4(t_stacks *stacks, char cur_sta);
void	sort_small_5(t_stacks *stacks, char cur_sta);
long long	get_stack_min(t_stacks *stacks, char cur_sta, long long n);

#endif
