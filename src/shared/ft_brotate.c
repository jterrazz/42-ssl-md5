/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:16:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:07:03 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

uint32_t ft_brotate_left(uint32_t x, char rotations)
{
    return ((x << rotations) | (x >> (32 - rotations)));
}

uint32_t ft_brotate_right(uint32_t x, char rotations)
{
    return ((x >> rotations) | (x << (32 - rotations)));
}

uint64_t ft_brotate_right_64(uint64_t x, char rotations)
{
    return ((x >> rotations) | (x << (64 - rotations)));
}
