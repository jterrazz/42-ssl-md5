/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/26 00:44:54 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha224.h"

char*ft_sha224(const char *msg, size_t msg_len)
{
    unsigned char	*formatted_msg;
    t_8_uint32		buffers;
    char *hash;
    char *cropped_hash;

    if (!(formatted_msg =
              build_msg(msg, msg_len,
                  SHA256_CHUNK_COUNT(msg_len) * SHA256_CHUNK_SIZE, FALSE)))
        return (NULL);

    ft_uint32_arr_cpy(buffers, g_sha224_default_buffers, 8);
    sha256_run_ops(buffers, formatted_msg, msg_len);
    free(formatted_msg);

    if (!(hash = build_hash(buffers, 8, FALSE)))
        return NULL;
    if (!(cropped_hash = malloc(sizeof(char) * 224 / 8 * 2 + 1))) // amcro
        return NULL;
    ft_strncpy(cropped_hash, hash, 224 / 8 * 2 );
    free(hash);
    return (cropped_hash);
}
