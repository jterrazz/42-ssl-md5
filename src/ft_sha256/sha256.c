/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:25:41 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha256.h"

// set number of round in macro
// Replace all these by generic function for sha512
static void init_w_array(t_64_uint32 w_array, unsigned char *formatted_msg)
{
    int i;

    i = 0;
    while (i < 64) {
        if (i < 16) {
            w_array[i] = ft_bswap_uint32(((uint32_t *)formatted_msg)[i]);
        } else {
            w_array[i] = sha256_op_d(w_array[i - 2]) + w_array[i - 7] +
                            sha256_op_c(w_array[i - 15]) +
                            w_array[i - 16];
        }
        i++;
    }
}

static void sha256_shuffle_buffers(t_8_uint32 buffers,
    t_64_uint32 w_array)
{
    int			i;
    uint32_t	temp_a;
    uint32_t	temp_b;

    i = 0;
    while (i < 64) {
        temp_a = buffers[7] + sha256_op_b(
            buffers[4]) + sha256_op_ch(buffers[4],
            buffers[5],
            buffers[6]) + g_sha256_k[i] + w_array[i];
        temp_b = sha256_op_a(buffers[0]) +
                 sha256_op_maj(buffers[0],
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

static void sha256_run_ops(t_8_uint32 buffers,
    unsigned char *formatted_msg,
    size_t msg_len)
{
    size_t		chunk_i;
    t_64_uint32	w_array;
    t_8_uint32		internal_buffers;

    chunk_i = 0;

    while (chunk_i < SHA256_CHUNK_COUNT(msg_len)) {
        init_w_array(w_array, formatted_msg + chunk_i * SHA256_CHUNK_SIZE);
        ft_uint32_arr_cpy(internal_buffers, buffers, 8);
        sha256_shuffle_buffers(internal_buffers, w_array);
        ft_uint32_arr_assign_add(buffers, internal_buffers, 8);
        chunk_i++;
    }
}

char*ft_sha256(const char *msg, size_t msg_len)
{
    unsigned char	*formatted_msg;
    t_8_uint32		buffers;

    if (!(formatted_msg =
              build_msg(msg, msg_len,
                  SHA256_CHUNK_COUNT(msg_len) * SHA256_CHUNK_SIZE, FALSE)))
        return (NULL);

    ft_uint32_arr_cpy(buffers, g_sha256_default_buffers, 8);
    sha256_run_ops(buffers, formatted_msg, msg_len);
    free(formatted_msg);

    return (build_hash(buffers, 8, FALSE));
}
