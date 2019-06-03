/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/06/03 23:24:32 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_uint32_list_assign_add(uint32_t *dst, const uint32_t *src, size_t length)
{
    size_t i = 0;

    while (i < length) {
        dst[i] += src[i];
        i++;
    }
}

void ft_uint32_list_cpy(uint32_t *dst, const uint32_t *src, size_t length)
{
    size_t i = 0;

    while (i < length) {
        dst[i] = src[i];
        i++;
    }
}
