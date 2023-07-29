/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:20:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/29 11:21:51 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	init_deques(t_stacks *stacks, long long capacity)
{
	deque_init(&stacks->a, capacity);
	if (!stacks->a.buffer)
		return (false);
	deque_init(&stacks->b, capacity);
	if (!stacks->b.buffer)
	{
		deque_free_buffer(&stacks->a);
		return (false);
	}
	return (true);
}

static bool	init_stacks(t_stacks *stacks, long long capacity)
{
	stacks->flag_print = false;
	stacks->instructions = ft_calloc(1, sizeof (char));
	if (!stacks->instructions)
		return (false);
	if (!init_deques(stacks, capacity))
		return (false);
	stacks->alpha = (long long *)ft_calloc(capacity, sizeof (long long));
	if (!stacks->alpha)
		return (false);
	stacks->beta = (long long *)ft_calloc(capacity, sizeof (long long));
	if (!stacks->beta)
	{
		free(stacks->alpha);
		return (false);
	}
	stacks->initialized = true;
	return (true);
}

static char	**extract_num_list(int argc, char **argv, bool *did_malloc)
{
	char		**num_list;

	if (argc == 2)
	{
		num_list = ft_split(argv[1], ' ');
		if (!num_list)
			return (NULL);
		*did_malloc = true;
	}
	else
	{
		num_list = (char **)ft_calloc(argc, sizeof (char *));
		if (!num_list)
			return (NULL);
		ft_memcpy(num_list, &argv[1], sizeof (char *) * (argc - 1));
		*did_malloc = false;
	}
	return (num_list);
}

static void	free_num_list(char **num_list)
{
	long long	idx;

	idx = 0;
	while (num_list[idx])
		free(num_list[idx++]);
	free(num_list);
}

bool	parse_arg(t_stacks *stacks, int argc, char **argv)
{
	bool		did_malloc;
	char		**num_list;
	long long	capacity;

	num_list = extract_num_list(argc, argv, &did_malloc);
	if (!num_list)
		return (false);
	capacity = get_arg_count(num_list);
	if (capacity < 1 || !is_valid_arg(num_list)
		|| !init_stacks(stacks, capacity))
	{
		if (did_malloc)
			free_num_list(num_list);
		else
			free(num_list);
		return (false);
	}
	compression(stacks, num_list);
	if (did_malloc)
		free_num_list(num_list);
	else
		free(num_list);
	return (true);
}
