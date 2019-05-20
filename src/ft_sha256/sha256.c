/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:39:43 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha256.h"
#include "libft.h"

static void init_w_array(t_64i_buffer *w_array, unsigned char *msg_buffer)
{
    int i;

    i = 0;
    while (i < 64) {
        if (i < 16) {
            w_array->i[i] = invert_uint32(((uint32_t *)msg_buffer)[i]);
        } else {
            w_array->i[i] = sha256_op_d(w_array->i[i - 2]) + w_array->i[i - 7] +
                            sha256_op_c(w_array->i[i - 15]) +
                            w_array->i[i - 16];
        }
        i++;
    }
}

static void sha256_tranform_buffers(t_8i_buffer internal_buffers,
    t_64i_buffer w_array)
{
    int			i;
    unsigned int	temp_a;
    unsigned int	temp_b;

    i = 0;
    while (i < 64) {
        temp_a = internal_buffers[7] + sha256_op_b(
            internal_buffers[4]) + sha256_op_ch(internal_buffers[4],
            internal_buffers[5],
            internal_buffers[6]) + g_sha256_k[i] + w_array.i[i];
        temp_b = sha256_op_a(internal_buffers[0]) +
                 sha256_op_maj(internal_buffers[0],
            internal_buffers[1],
            internal_buffers[2]);
        internal_buffers[7]	= internal_buffers[6];
        internal_buffers[6]	= internal_buffers[5];
        internal_buffers[5]	= internal_buffers[4];
        internal_buffers[4]	= internal_buffers[3] + temp_a;
        internal_buffers[3]	= internal_buffers[2];
        internal_buffers[2]	= internal_buffers[1];
        internal_buffers[1]	= internal_buffers[0];
        internal_buffers[0]	= temp_a + temp_b;
        i++;
    }
}

static void sha256_run_ops(t_8i_buffer buffers,
    unsigned char *msg_buffer,
    size_t msg_len)
{
    size_t		chunk_i;
    t_64i_buffer	w_array;
    t_8i_buffer		internal_buffers;

    chunk_i = 0;

    while (chunk_i < CHUNK_COUNT(msg_len)) {
        init_w_array(&w_array, msg_buffer += chunk_i * CHUNK_SIZE);
        ft_buffer_copy(internal_buffers, buffers, 8);
        sha256_tranform_buffers(internal_buffers, w_array);
        ft_buffer_assign_add(buffers, internal_buffers, 8);
        chunk_i++;
    }
}

char*sha256(const char *msg, size_t msg_len)
{
    unsigned char	*msg_buffer;
    t_8i_buffer		buffers;

    if (!(msg_buffer =
              ft_ssl_msg_padding(msg, msg_len,
                  CHUNK_COUNT(msg_len) * CHUNK_SIZE, FALSE)))
        return (NULL);

    ft_buffer_copy(buffers, g_sha256_default_buffers, 8);
    sha256_run_ops(buffers, msg_buffer, msg_len);
    free(msg_buffer);

    return (build_hash(buffers, 8, FALSE));
}
