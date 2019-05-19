/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/09 17:45:13 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shared.h"

void ft_buffer_assign_add(unsigned int *dst, const unsigned int *src, size_t length) {
    size_t i = 0;

    while (i < length){
        dst[i] += src[i];
        i++;
    }
}

void ft_buffer_copy(unsigned int *dst, const unsigned int *src, size_t length) {
    size_t i = 0;

    while (i < length) {
        dst[i] = src[i];
        i++;
    }
}
