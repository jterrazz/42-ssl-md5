/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:15:32 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:41:20 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./md5.h"

unsigned int md5_op_shift_1(unsigned int buffers[])
{
    return ((buffers[1] & buffers[2]) | (~buffers[1] & buffers[3]));
}

unsigned int md5_op_shift_2(unsigned int buffers[])
{
    return ((buffers[1] & buffers[3]) | (buffers[2] & ~buffers[3]));
}

unsigned int md5_op_shift_3(unsigned int buffers[])
{
    return (buffers[1] ^ buffers[2] ^ buffers[3]);
}

unsigned int md5_op_shift_4(unsigned int buffers[])
{
    return (buffers[2] ^ (buffers[1] | ~buffers[3]));
}
