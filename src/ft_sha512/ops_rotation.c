/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:37:27 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:43:25 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha512.h"

uint64_t	sha512_op_a(uint64_t x)
{
	return (ft_brotate_right_64(x, 28) ^ ft_brotate_right_64(x, 34) ^ ft_brotate_right_64(x, 39));
}

uint64_t	sha512_op_b(uint64_t x)
{
	return (ft_brotate_right_64(x, 14) ^ ft_brotate_right_64(x, 18) ^ ft_brotate_right_64(x, 41));
}

uint64_t	sha512_op_c(uint64_t x)
{
	return (ft_brotate_right_64(x, 1) ^ ft_brotate_right_64(x, 8) ^ (x >> 7));
}

uint64_t	sha512_op_d(uint64_t x)
{
	return (ft_brotate_right_64(x, 19) ^ ft_brotate_right_64(x, 61) ^ (x >> 6));
}
