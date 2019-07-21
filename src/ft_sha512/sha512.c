/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:26:28 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha512.h"

// If generic, add uin64 param and resolve the w_array uint32/64 issue;
static void init_w_array(t_80_uint64 w_array, unsigned char *formatted_msg)
{
    int i;

    i = 0;
    // Macro W array length
    while (i < 80) {
        if (i < 16) {
            w_array[i] = ft_bswap_uint64(((uint64_t *)formatted_msg)[i]);
        } else {
            w_array[i] = sha512_op_d(w_array[i - 2]) + w_array[i - 7] +
                            sha512_op_c(w_array[i - 15]) +
                            w_array[i - 16];
        }
        i++;
    }
}

static void sha512_shuffle_buffers(t_8_uint64 buffers,
    t_80_uint64 w_array)
{
    int			i;
    uint64_t	temp_a;
    uint64_t	temp_b;

    i = 0;
    while (i < 80) {
        temp_a = buffers[7] + sha512_op_b(
            buffers[4]) + sha512_op_ch(buffers[4], // Replace ft by generic sha name
            buffers[5],
            buffers[6]) + g_sha512_k[i] + w_array[i];
        temp_b = sha512_op_a(buffers[0]) +
                 sha512_op_maj(buffers[0],
            buffers[1],
            buffers[2]);
        buffers[7]	= buffers[6];
        buffers[6]	= buffers[5];
        buffers[5]	= buffers[4];
        buffers[4]	= buffers[3] + temp_a;
        buffers[3]	= buffers[2];
        buffers[2]	= buffers[1];
        buffers[1]	= buffers[0];
        buffers[0]	= temp_a + temp_b;
        i++;
    }
}

static void sha512_run_ops(t_8_uint64 buffers,
    unsigned char *formatted_msg,
    size_t msg_len)
{
    size_t		chunk_i;
    t_80_uint64	w_array;
    t_8_uint64		internal_buffers;

    chunk_i = 0;

    while (chunk_i < SHA512_CHUNK_COUNT(msg_len)) {
        init_w_array(w_array, formatted_msg + chunk_i * SHA512_CHUNK_SIZE);
        ft_uint64_arr_cpy(internal_buffers, buffers, 8);
        sha512_shuffle_buffers(internal_buffers, w_array);
        ft_uint64_arr_assign_add(buffers, internal_buffers, 8);
        chunk_i++;
    }
}

char*ft_sha512(const char *msg, size_t msg_len)
{
    unsigned char	*formatted_msg;
    t_8_uint64		buffers;

    if (!(formatted_msg =
              build_msg(msg, msg_len,
                  SHA512_CHUNK_COUNT(msg_len) * SHA512_CHUNK_SIZE, FALSE)))
        return (NULL);

    ft_uint64_arr_cpy(buffers, g_sha512_default_buffers, 8);
    sha512_run_ops(buffers, formatted_msg, msg_len);
    free(formatted_msg);

    return (build_hash_64(buffers, 8, FALSE)); // replace 16 and 8 by MACROS
}
