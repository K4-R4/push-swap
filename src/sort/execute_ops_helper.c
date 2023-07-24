/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ops_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:57:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 17:57:51 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	convert_idx_to_ops(long long idx, long long sta_sz)
{
	if (idx <= sta_sz / 2)
		return (idx);
	else
		return (idx - sta_sz);
}
