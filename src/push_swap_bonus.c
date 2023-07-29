/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:42:55 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/29 19:15:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q checker");
}
*/

static char	**read_instrs(void)
{
	long long	idx;
	char		**instrs;
	char		**tmp;

	idx = 0;
	instrs = (char **)ft_calloc(idx + 2, sizeof (char *));
	if (!instrs)
		return (NULL);
	instrs[idx] = get_next_line(STDIN_FILENO);
	while (instrs[idx])
	{
		idx++;
		tmp = instrs;
		instrs = (char **)ft_calloc(idx + 2, sizeof (char *));
		ft_memcpy(instrs, tmp, sizeof (char *) * idx);
		instrs[idx] = get_next_line(STDIN_FILENO);
		free(tmp);
	}
	return (instrs);
}

static void	execute_instrs_helper(t_stacks *stacks, char *instr)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		stack_sa(stacks);
	if (ft_strcmp(instr, "sb\n") == 0)
		stack_sb(stacks);
	if (ft_strcmp(instr, "ss\n") == 0)
		stack_ss(stacks);
	if (ft_strcmp(instr, "pa\n") == 0)
		stack_pa(stacks);
	if (ft_strcmp(instr, "pb\n") == 0)
		stack_pb(stacks);
	if (ft_strcmp(instr, "ra\n") == 0)
		stack_ra(stacks);
	if (ft_strcmp(instr, "rb\n") == 0)
		stack_rb(stacks);
	if (ft_strcmp(instr, "rr\n") == 0)
		stack_rr(stacks);
	if (ft_strcmp(instr, "rra\n") == 0)
		stack_rra(stacks);
	if (ft_strcmp(instr, "rrb\n") == 0)
		stack_rrb(stacks);
	if (ft_strcmp(instr, "rrr\n") == 0)
		stack_rrr(stacks);
}

static void	execute_instrs(t_stacks *stacks, char **instrs)
{
	const char	*valid_instrs[] = {"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	size_t		idx;

	while (*instrs)
	{
		idx = 0;
		while (valid_instrs[idx])
		{
			if (ft_strcmp(*instrs, (char *)valid_instrs[idx]) == 0)
				break ;
			idx++;
		}
		if (idx >= sizeof (valid_instrs) / sizeof (valid_instrs[0]) - 1)
			my_exit(STDERR_FILENO, "Error\n", stacks, 1);
		execute_instrs_helper(stacks, *instrs);
		instrs++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**instrs;

	stacks.initialized = false;
	if (argc <= 1)
		my_exit(STDOUT_FILENO, NULL, &stacks, 1);
	if (!parse_arg(&stacks, argc, argv))
		my_exit(STDERR_FILENO, "Error\n", &stacks, 1);
	instrs = read_instrs();
	if (!instrs)
		my_exit(STDERR_FILENO, "Error\n", &stacks, 1);
	execute_instrs(&stacks, instrs);
	if (is_sorted(&stacks))
		my_exit(STDOUT_FILENO, "OK\n", &stacks, 0);
	else
		my_exit(STDOUT_FILENO, "KO\n", &stacks, 1);
}
