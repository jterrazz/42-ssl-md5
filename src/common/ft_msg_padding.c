/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:51:55 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/09 18:47:47 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/common.h"
#include "libft.h"

static void add_little_endian_size(unsigned char *start, size_t byte_size) {
    t_l_buffer long_buffer;

    long_buffer.l = 8 * byte_size;
    ft_memcpy(start, long_buffer.c, 8);
}

static void add_big_endian_size(unsigned char *start, size_t byte_size) {
    int i;
    t_l_buffer l_buffer;

    i = 0;
    l_buffer.l = 8 * byte_size;

    while (i < 8) {
        start[i] = l_buffer.c[7 - i];
        i++;
    }
}

unsigned char *ft_ssl_msg_padding(const char *msg, size_t msg_len, size_t new_len, bool is_little_endian) {
    size_t cursor;
    unsigned char *msg_buffer;

    if (!(msg_buffer = malloc(new_len)))
        return (NULL);

    ft_memcpy(msg_buffer, msg, msg_len);
    msg_buffer[msg_len] = 0b10000000;
    cursor = msg_len + 1;

    while (cursor < new_len)
        msg_buffer[cursor++] = 0;

    if (is_little_endian) {
        add_little_endian_size(msg_buffer + cursor - 8, msg_len);
    } else {
        add_big_endian_size(msg_buffer + cursor - 8, msg_len);
    }

    return (msg_buffer);
}
