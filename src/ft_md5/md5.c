/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:55:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/09 18:47:21 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"// Delte
#include "./md5.h"// Delte

// Explainations: a chunk is 64 bits or 512 bits // A chunk is a 512 bits part of the buffer;
// Create debugger to show author, all includes, check all functions called
// https://crypto.stackexchange.com/questions/10829/why-initialize-sha1-with-specific-buffer
// Append 1 bit to the message + length so its 4 bits (int) + 4 bits (int)
// Test and compare with length from 0 to 512 + try sending empty files
// Take the wikipedia algorythm to explain

static void run_md5_byte_ops(int i, t_16i_buffer chunk, t_4i_buffer tmp_buffers) {
    static t_bits_ops ft_f[4] = { &md5_op_shift_1, &md5_op_shift_2, &md5_op_shift_3, &md5_op_shift_4 };
    static t_g_ops ft_g[4] = { &md5_op_g_1, &md5_op_g_2, &md5_op_g_3, &md5_op_g_4 };

    t_bits_ops f;
    t_g_ops g;
    int f_result;

    g = ft_g[i / 16];
    f = ft_f[i / 16];
    f_result = f(tmp_buffers) + tmp_buffers[0] + g_computed_sines[i] + chunk.i[g(i)];
    tmp_buffers[0] = tmp_buffers[3];
    tmp_buffers[3] = tmp_buffers[2];
    tmp_buffers[2] = tmp_buffers[1];
    tmp_buffers[1] = tmp_buffers[1] + ft_rotate_bits_left(f_result, g_md5_shifts[i]);
}

// MD5 uses a buffer that is made up of four words that are each 32 bits long => 4 bytes => int
static void run_md5_operations(unsigned char *padded_msg, size_t msg_len, t_4i_buffer buffers) {
    size_t chunk_i;
    int chunk_cursor;
    t_16i_buffer chunk;
    t_4i_buffer tmp_buffers;

    chunk_i = 0;
    chunk_cursor = 0;

    ft_buffer_copy(buffers, g_md5_default_buffers, 4);

    while (chunk_i < CHUNK_COUNT(msg_len)) {
        ft_memcpy(chunk.c, padded_msg + chunk_i * CHUNK_SIZE, CHUNK_SIZE);
        chunk_cursor = 0;

        ft_buffer_copy(tmp_buffers, buffers, 4);
        while (chunk_cursor < 64)
            run_md5_byte_ops(chunk_cursor++, chunk, tmp_buffers);
        ft_buffer_assign_add(buffers, tmp_buffers, 4);
        chunk_i++;
    }
}

char *md5(const char *msg, size_t msg_len) {
    unsigned char *padded_msg;
    t_4i_buffer buffers;

    if (!(padded_msg = ft_ssl_msg_padding(msg, msg_len, CHUNK_COUNT(msg_len) * CHUNK_SIZE, TRUE)))
        return NULL;

    run_md5_operations(padded_msg, msg_len, buffers);
    free(padded_msg);

    return (build_hash(buffers, 4, TRUE));
}
