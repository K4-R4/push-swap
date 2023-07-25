/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:56:50 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/25 19:11:40 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "parser.h"
# include "deque.h"
# include "stack.h"
# include "sort.h"

long long	convert_idx_to_ops(long long idx, long long sta_sz);
long long	my_abs(long long nbr);
long long	my_min(long long a, long long b);
long long	my_exit(int fd, char *message, t_stacks *stacks, int exit_code);

#endif
