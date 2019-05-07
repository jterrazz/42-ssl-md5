/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:39:14 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 18:55:57 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"
#include "libft.h"

char *build_hash(t_8i_buffer buffers, size_t buffer_count, size_t hash_size) {
    char *hash;
    t_i_buffer int_buffer;
    size_t buffer_i;
    int i;
    char *hash_part;

    hash_size = hash_size / 8 * 2;
    if (!(hash = ft_strnew(hash_size + 2)))
        return (NULL);

    ft_strncpy(hash, "0x", 2);
    i = 0;
    while (i < 4) {
        int_buffer.i = buffers[i];
        buffer_i = 0;
        while (buffer_i < buffer_count) {
            if (!(hash_part = ft_uitoa_base_len(int_buffer.c[buffer_i], 16, 'a', 2)))
                return (NULL);
            ft_strncpy(hash + 2 + buffer_i * 2 + (i * (hash_size / 4)), hash_part, hash_size / 4); // j * 2 = because we print 2 caracters per byte ; + 2 because of 0x; (i * (HASH_SIZE / 4)) for each buffer
            free(hash_part);
            buffer_i++;
        }
        i++;
    }
    return hash;
}
