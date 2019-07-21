/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:08:16 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_uint32_arr_assign_add(uint32_t *dst, const uint32_t *src, size_t len)
{
    size_t i = 0;

    while (i < len) {
        dst[i] += src[i];
        i++;
    }
}

void ft_uint32_arr_cpy(uint32_t *dst, const uint32_t *src, size_t len)
{
    size_t i = 0;

    while (i < len) {
        dst[i] = src[i];
        i++;
    }
}

void ft_uint64_arr_assign_add(uint64_t *dst, const uint64_t *src, size_t len)
{
    size_t i = 0;

    while (i < len) {
        dst[i] += src[i];
        i++;
    }
}

void ft_uint64_arr_cpy(uint64_t *dst, const uint64_t *src, size_t len)
{
    size_t i = 0;

    while (i < len) {
        dst[i] = src[i];
        i++;
    }
}
