/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:07:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/18 16:44:31 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
#define PUSH_H

#include "stack.h"

void	sort(t_stacks *stacks);
void	sort_2(t_stacks *stacks, char cur_sta);
void	sort_3(t_stacks *stacks, char cur_sta);
void	sort_4(t_stacks *stacks, char cur_sta);
void	sort_5(t_stacks *stacks, char cur_sta);
void	sort_many(t_stacks *stacks);
void		push_a_back(t_stacks *stacks);

#endif
