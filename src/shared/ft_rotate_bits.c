/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:16:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:50:33 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

uint32_t ft_rotate_bits_left(uint32_t x, char rotations)
{
    return ((x << rotations) | (x >> (32 - rotations)));
}

uint32_t ft_rotate_bits_right(uint32_t x, char rotations)
{
    return ((x >> rotations) | (x << (32 - rotations)));
}
