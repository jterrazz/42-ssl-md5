/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:27:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:53:58 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

uint32_t sha256_op_ch(uint32_t x, uint32_t y, uint32_t z)
{
    return ((x & y) ^ (~x & z));
}

uint32_t sha256_op_maj(uint32_t x, uint32_t y, uint32_t z)
{
    return ((x & y) ^ (x & z) ^ (y & z));
}
