/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:27:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/05 00:47:19 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./md5.h"

void add_buffers(t_buffer_group dst, t_buffer_group src, int length) {
    int i = 0;

    while (i < length){
        dst[i] += src[i];
        i++;
    }
}

void copy_buffers(t_buffer_group dst, t_buffer_group src, int length) {
    int i = 0;

    while (i < length) {
        dst[i] = src[i];
        i++;
    }
}
