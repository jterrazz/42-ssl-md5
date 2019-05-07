/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/06 13:13:29 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void add_buffers(unsigned int *dst, const unsigned int *src, int length) {
    int i = 0;

    while (i < length){
        dst[i] += src[i];
        i++;
    }
}

void copy_buffers(unsigned int *dst, const unsigned int *src, int length) {
    int i = 0;

    while (i < length) {
        dst[i] = src[i];
        i++;
    }
}
