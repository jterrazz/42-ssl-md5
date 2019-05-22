/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:35:31 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:54:38 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

uint32_t md5_op_g_1(uint32_t i)
{
    return (i);
}

uint32_t md5_op_g_2(uint32_t i)
{
    return ((5 * i + 1) % 16);
}

uint32_t md5_op_g_3(uint32_t i)
{
    return ((3 * i + 5) % 16);
}

uint32_t md5_op_g_4(uint32_t i)
{
    return ((7 * i) % 16);
}
