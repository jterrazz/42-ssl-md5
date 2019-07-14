/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:27:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/14 15:28:19 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

uint64_t sha512_op_ch(uint64_t x, uint64_t y, uint64_t z)
{
    return ((x & y) ^ (~x & z));
}

uint64_t sha512_op_maj(uint64_t x, uint64_t y, uint64_t z)
{
    return ((x & y) ^ (x & z) ^ (y & z));
}