/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:39:14 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:51:51 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shared.h"
#include "libft.h"

static bool build_hash_big_endian(t_8i_buffer buffers,
    size_t buffer_i,
    char *hash)
{
    char *hash_tmp;

    if (!(hash_tmp = ft_uitoa_base_len(buffers[buffer_i], 16, 'a', 8)))
        return (FALSE);

    ft_strncpy(hash + (buffer_i * 8), hash_tmp, 8);
    free(hash_tmp);

    return (TRUE);
}

static bool build_hash_little_endian(t_8i_buffer buffers,
    size_t buffer_i,
    char *hash)
{
    char	*hash_tmp;
    t_i_buffer	int_buffer;
    int		i;

    int_buffer.i	= buffers[buffer_i];
    i			= 0;

    while (i < 4) {
        if (!(hash_tmp =
                  ft_uitoa_base_len(int_buffer.c[i], 16, 'a', 2)))
            return (FALSE);

        ft_strncpy(hash + i * 2 + (buffer_i * 8), hash_tmp, 8);
        free(hash_tmp);
        i++;
    }

    return (TRUE);
}

// TODO Check what upper of lower case to use
char*build_hash(t_8i_buffer buffers, size_t buffer_count, bool is_little_endian)
{
    char	*hash;
    size_t	buffer_i;

    buffer_i = 0;
    if (!(hash = ft_strnew(buffer_count * 8)))
        return (NULL);

    while (buffer_i < buffer_count) {
        if (is_little_endian) {
            build_hash_little_endian(buffers, buffer_i, hash);
        } else {
            build_hash_big_endian(buffers, buffer_i, hash);
        }
        buffer_i++;
    }

    return (hash);
}
