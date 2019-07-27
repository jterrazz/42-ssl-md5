/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:15:32 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:31:07 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

uint32_t	md5_op_shift_1(uint32_t buffers[])
{
	return ((buffers[1] & buffers[2]) | (~buffers[1] & buffers[3]));
}

uint32_t	md5_op_shift_2(uint32_t buffers[])
{
	return ((buffers[1] & buffers[3]) | (buffers[2] & ~buffers[3]));
}

uint32_t	md5_op_shift_3(uint32_t buffers[])
{
	return (buffers[1] ^ buffers[2] ^ buffers[3]);
}

uint32_t	md5_op_shift_4(uint32_t buffers[])
{
	return (buffers[2] ^ (buffers[1] | ~buffers[3]));
}
