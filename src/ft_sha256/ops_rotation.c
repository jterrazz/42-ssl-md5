/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:27:28 by jterrazz          #+#    #+#             */
/*   Updated: 2019/06/05 00:06:22 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha256.h"

uint32_t sha256_op_a(uint32_t x)
{
    return (ft_brotate_right(x,
        2) ^ ft_brotate_right(x, 13) ^ ft_brotate_right(x, 22));
}

uint32_t sha256_op_b(uint32_t x)
{
    return (ft_brotate_right(x,
        6) ^ ft_brotate_right(x, 11) ^ ft_brotate_right(x, 25));
}

uint32_t sha256_op_c(uint32_t x)
{
    return (ft_brotate_right(x,
        7) ^ ft_brotate_right(x, 18) ^ (x >> 3));
}

uint32_t sha256_op_d(uint32_t x)
{
    return (ft_brotate_right(x,
        17) ^ ft_brotate_right(x, 19) ^ (x >> 10));
}
