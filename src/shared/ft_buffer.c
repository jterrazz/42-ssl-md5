/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:52:31 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_buffer_assign_add(uint32_t *dst, const uint32_t *src, size_t length)
{
    size_t i = 0;

    while (i < length) {
        dst[i] += src[i];
        i++;
    }
}

void ft_buffer_copy(uint32_t *dst, const uint32_t *src, size_t length)
{
    size_t i = 0;

    while (i < length) {
        dst[i] = src[i];
        i++;
    }
}
