/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:55:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 18:15:13 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./md5.h"
#include "libft.h"

static void run_md5_byte_ops(int i, t_16i_buffer chunk, t_4_uint32 tmp_buffers)
{
    static t_ops_buffer ft_f[4] =
    { &md5_op_shift_1, &md5_op_shift_2, &md5_op_shift_3, &md5_op_shift_4 };
    static t_ops_1a ft_g[4] =
    { &md5_op_g_1, &md5_op_g_2, &md5_op_g_3, &md5_op_g_4 };

    t_ops_buffer	f;
    t_ops_1a		g;
    uint32_t		f_result;

    g		= ft_g[i / 16];
    f		= ft_f[i / 16];
    f_result	= f(tmp_buffers) + tmp_buffers[0] +
                  g_computed_sines[i] + chunk.i[g(i)];
    tmp_buffers[0]	= tmp_buffers[3];
    tmp_buffers[3]	= tmp_buffers[2];
    tmp_buffers[2]	= tmp_buffers[1];
    tmp_buffers[1]	= tmp_buffers[1] + ft_rotate_bits_left(f_result,
        g_md5_shifts[i]);
}

static void md5_transform_buffers(unsigned char *padded_msg,
    size_t msg_len,
    t_4_uint32 buffers)
{
    size_t		chunk_i;
    size_t			chunk_cursor;
    t_16i_buffer	chunk;
    t_4_uint32		tmp_buffers;

    chunk_i		= 0;
    chunk_cursor	= 0;

    ft_buffer_copy(buffers, g_md5_default_buffers, 4);

    while (chunk_i < MD5_CHUNK_COUNT(msg_len)) {
        ft_memcpy(chunk.c, padded_msg + chunk_i * MD5_CHUNK_SIZE,
            MD5_CHUNK_SIZE);
        chunk_cursor = 0;

        ft_buffer_copy(tmp_buffers, buffers, 4);
        while (chunk_cursor < 64)
            run_md5_byte_ops(chunk_cursor++, chunk, tmp_buffers);
        ft_buffer_assign_add(buffers, tmp_buffers, 4);
        chunk_i++;
    }
}

char*md5(const char *msg, size_t msg_len)
{
    unsigned char	*padded_msg;
    t_4_uint32		buffers;

    if (!(padded_msg =
              ft_ssl_msg_padding(msg, msg_len,
                  MD5_CHUNK_COUNT(msg_len) * MD5_CHUNK_SIZE, TRUE)))
        return (NULL);

    md5_transform_buffers(padded_msg, msg_len, buffers);
    free(padded_msg);

    return (build_hash(buffers, 4, TRUE));
}
