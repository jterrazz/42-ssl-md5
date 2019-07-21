/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:39:14 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:26:37 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shared.h"

char*build_hash(uint32_t *buffers, size_t buffer_count, bool is_little_endian)
{
    char	*hash;
    char	*hash_tmp;
    size_t	buffer_i;
    uint32_t buffer;

    buffer_i = 0;
    if (!(hash = ft_strnew(buffer_count * 8)))
        return (NULL);

    while (buffer_i < buffer_count) {
        buffer = is_little_endian ? ft_bswap_uint32(buffers[buffer_i]) : buffers[buffer_i];

        if (!(hash_tmp = ft_uitoa_base_len(buffer, 16, 'a', 8)))
            return (NULL);

        ft_strncpy(hash + (buffer_i * 8), hash_tmp, 8);
        free(hash_tmp);
        buffer_i++;
    }

    return (hash);
}

char*build_hash_64(uint64_t *buffers, size_t buffer_count, bool is_little_endian)
{
    char	*hash;
    char	*hash_tmp;
    size_t	buffer_i;
    uint64_t buffer;

    buffer_i = 0;
    if (!(hash = ft_strnew(buffer_count * 16)))
        return (NULL);

    while (buffer_i < buffer_count) {
        buffer = is_little_endian ? ft_bswap_uint64(buffers[buffer_i]) : buffers[buffer_i];

        if (!(hash_tmp = ft_uitoa_base_len(buffer, 16, 'a', 16)))
            return (NULL);

        ft_strncpy(hash + (buffer_i * 16), hash_tmp, 16);
        free(hash_tmp);
        buffer_i++;
    }

    return (hash);
}
