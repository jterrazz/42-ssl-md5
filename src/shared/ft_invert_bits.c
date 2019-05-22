/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invert_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 23:31:01 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:51:45 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shared.h"

uint32_t invert_uint32(uint32_t x)
{
    t_i_buffer buffer;

    buffer.i = x;
    return ((buffer.c[0] << 24) | (buffer.c[1] << 16) | (buffer.c[2] << 8) |
            (buffer.c[3]));
}
