/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:07:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 16:58:19 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

void	sort(t_stacks *stacks);
void	sort_2(t_stacks *stacks, bool on_a);
void	sort_3_a(t_stacks *stacks);
void	sort_4_a(t_stacks *stacks);
void	sort_5_a(t_stacks *stacks);
void	sort_many(t_stacks *stacks);
void	simulate_ops(t_stacks *stacks);
void	execute_ops(t_stacks *stacks);

#endif
