/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:39:14 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/09 17:29:08 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"
#include "libft.h"
#include "ft_printf.h" // TODO Remove
// TODO Typedef bool in return

int build_hash_big_endian(t_8i_buffer buffers, size_t buffer_i, char *hash) {
    char *hash_tmp;

    if (!(hash_tmp = ft_uitoa_base_len(buffers[buffer_i], 16, 'a', 8)))
        return (0);
    ft_strncpy(hash + 2 + (buffer_i * 8), hash_tmp, 8); // j * 2 = because we print 2 caracters per byte ; + 2 because of 0x; (i * (HASH_SIZE / 4)) for each buffer
    free(hash_tmp);
    return (1);
}

int build_hash_little_endian(t_8i_buffer buffers, size_t buffer_i, char *hash) {
    char *hash_tmp;
    t_i_buffer int_buffer;
    int i;

    int_buffer.i = buffers[buffer_i];
    i = 0;

    while (i < 4) {
        if (!(hash_tmp = ft_uitoa_base_len(int_buffer.c[i], 16, 'a', 2)))
            return (0);
        ft_strncpy(hash + 2 + i * 2 + (buffer_i * 8), hash_tmp, 8); // j * 2 = because we print 2 caracters per byte ; + 2 because of 0x; (i * (HASH_SIZE / 4)) for each buffer
        free(hash_tmp);
        i++;
    }
    return (1);
}

char *build_hash(t_8i_buffer buffers, size_t buffer_count, int is_little_endian) { // TODO Use bool
    char *hash;
    size_t buffer_i;

    buffer_i = 0;
    if (!(hash = ft_strnew(buffer_count * 8 + 2)))
        return (NULL);
    ft_strncpy(hash, "0x", 2);

    while (buffer_i < buffer_count) {
        if (is_little_endian) {
            build_hash_little_endian(buffers, buffer_i, hash);
        } else {
            build_hash_big_endian(buffers, buffer_i, hash);
        }
        buffer_i++;
    }
    return hash;
}
