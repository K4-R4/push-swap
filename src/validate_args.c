/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:28:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/11 16:12:28 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// args must be separated by space(s)
bool	is_valid_arg(char **num_list)
{
	bool	is_valid;
	bool	is_negative;

	is_valid = true;
	while (*num_list)
	{
		is_negative = *num_list[0] == '-';
		if (ft_strlen(*num_list) - is_negative !=
				(unsigned int)get_digit_count(ft_atoi(*num_list), 10))
			return (false);
		num_list++;
	}
	return (is_valid);
}
