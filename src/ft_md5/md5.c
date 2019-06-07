/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:55:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/06/07 15:35:44 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./md5.h"
#include "libft.h"

static const t_ops_buffer ft_f[4] =
{ &md5_op_shift_1, &md5_op_shift_2, &md5_op_shift_3, &md5_op_shift_4 };

static const t_ops_1a ft_g[4] =
{ &md5_op_g_1, &md5_op_g_2, &md5_op_g_3, &md5_op_g_4 };

static void md5_shuffle_buffers(int i, t_16_uint32 chunk, t_4_uint32 buffers)
{
    t_ops_buffer	f;
    t_ops_1a		g;
    uint32_t		f_result;

    g		= ft_g[i / 16];
    f		= ft_f[i / 16];
    f_result	= f(buffers) + buffers[0] +
                  g_computed_sines[i] + chunk[g(i)];
    buffers[0]	= buffers[3];
    buffers[3]	= buffers[2];
    buffers[2]	= buffers[1];
    buffers[1]	= buffers[1] + ft_brotate_left(f_result,
        g_md5_shifts[i]);
}

static void md5_run_ops(unsigned char *padded_msg,
    size_t msg_len,
    t_4_uint32 buffers)
{
    size_t	chunk_i;
    size_t	chunk_cursor;
    t_16_uint32 chunk;
    t_4_uint32	tmp_buffers;

    chunk_i		= 0;
    chunk_cursor	= 0;

    ft_uint32_list_cpy(buffers, g_md5_default_buffers, 4);

    while (chunk_i < MD5_CHUNK_COUNT(msg_len)) {
        ft_memcpy(chunk, padded_msg + chunk_i * MD5_CHUNK_SIZE,
            MD5_CHUNK_SIZE);
        chunk_cursor = 0;

        ft_uint32_list_cpy(tmp_buffers, buffers, 4);
        while (chunk_cursor < 64)
            md5_shuffle_buffers(chunk_cursor++, chunk, tmp_buffers);
        ft_uint32_list_assign_add(buffers, tmp_buffers, 4);
        chunk_i++;
    }
}

char*ft_md5(const char *msg, size_t msg_len)
{
    unsigned char	*padded_msg;
    t_4_uint32		buffers;

    if (!(padded_msg = build_msg(msg, msg_len,
        MD5_CHUNK_COUNT(msg_len) * MD5_CHUNK_SIZE, TRUE)))
        return (NULL);

    md5_run_ops(padded_msg, msg_len, buffers);
    free(padded_msg);

    return (build_hash(buffers, 4, TRUE));
}
