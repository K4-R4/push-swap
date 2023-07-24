/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:50 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 16:57:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "deque.h"
# include "stack.h"
# include "sort.h"

bool		is_valid_arg(char **num_list);
bool		parse_arg(t_stacks *stacks, int argc, char **argv);
long long	convert_idx_to_ops(long long idx, long long sta_sz);
long long	my_abs(long long nbr);
long long	my_min(long long a, long long b);
long long	my_exit(char *message, int exit_code);

#endif
