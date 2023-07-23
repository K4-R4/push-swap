/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:49:47 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 20:47:21 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_save_instruction(t_stacks *stacks, char *instruction)
{
	char	*instruction_dup;
	char	*new_instructions;

	instruction_dup = ft_strdup(instruction);
	if (!instruction_dup)
		my_exit(NULL, 1);
	new_instructions = ft_strjoin(stacks->instructions, instruction_dup);
	if (!new_instructions)
		my_exit(NULL, 1);
}
