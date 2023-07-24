/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:18:41 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 20:30:32 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "deque.h"
# include "stack.h"

bool		is_valid_arg(char **num_list);
bool		parse_arg(t_stacks *stacks, int argc, char **argv);
long long	get_arg_count(char **num_list);
void		compression(t_stacks *stacks, char **num_list);

#endif