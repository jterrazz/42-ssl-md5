/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 18:56:48 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha256.h"
#include "libft.h"

# define CHUNK_COUNT(msg_len) (1 + (msg_len + 8) / CHUNK_SIZE ) // TODO Use modulo ??? Use + 1 inside ?
# define CHUNK_SIZE 64 // 512 bits

// TODO Delete for common one
static unsigned char *init_msg_buffer(const char *msg, size_t msg_len) {
    int cursor;
    int chunk_number;
    unsigned char *msg_buffer;
    t_i_buffer final_length_buffer;

    cursor = 0;
    chunk_number = CHUNK_COUNT(msg_len);
    msg_buffer = malloc(chunk_number * CHUNK_SIZE);
    if (!msg_buffer)
        return NULL;

    ft_memcpy(msg_buffer, msg, msg_len);
    msg_buffer[msg_len] = 0b10000000;

    cursor = msg_len + 1;
    while (cursor < chunk_number * CHUNK_SIZE) // TODO Transform to a cursor
        msg_buffer[cursor++] = 0;
    cursor -= 8; // Because we add '0' with => bits ≡ 448 (mod 512)
    final_length_buffer.i = 8 * msg_len; // Because it was set to 0, the size is % 2^64 ?????
    ft_memcpy(msg_buffer + cursor, final_length_buffer.c, 4);

    return msg_buffer;
}

static void init_w_array(t_64i_buffer w_array, unsigned char *msg_buffer) {
    int i;

    i = 16;
    copy_buffers(w_array.i, (unsigned int *)msg_buffer, 16);
    while (i < 64) {
        w_array.i[i] = sha256_op_d(w_array.i[i - 2]) + w_array.i[i - 7] + sha256_op_c(w_array.i[i - 15]) + w_array.i[i - 16];
        i++;
    }
}

static void run_sha256_internal_operations(t_8i_buffer internal_buffers, t_64i_buffer w_array) {
    int i;
    unsigned int temp_a;// TODO Put unsigned everywhere
    unsigned int temp_b;

    i = 0;
    while (i < 64) {
        temp_a = internal_buffers[7] + sha256_op_b(internal_buffers[4]) + sha256_op_ch(internal_buffers[4], internal_buffers[5], internal_buffers[6]) + g_k[i] + w_array.i[i];
        temp_b = sha256_op_a(internal_buffers[0]) + sha256_op_maj(internal_buffers[0],internal_buffers[1],internal_buffers[2]);
        internal_buffers[7] = internal_buffers[6];
        internal_buffers[6] = internal_buffers[5];
        internal_buffers[5] = internal_buffers[4];
        internal_buffers[4] = internal_buffers[3] + temp_a;
        internal_buffers[3] = internal_buffers[2];
        internal_buffers[2] = internal_buffers[1];
        internal_buffers[1] = internal_buffers[0];
        internal_buffers[0] = temp_a + temp_b;
        i++;
    }
}

// Maybe make general ft for iteration in chunks
static void run_sha256_operations(t_8i_buffer buffers, unsigned char *msg_buffer, size_t msg_len) {
    size_t chunk_i;
    t_64i_buffer w_array;
    t_8i_buffer internal_buffers;
    // 16 mots de 4 bytes donc 16 unsigned int

    chunk_i = 0;
    // TODO Test with super long strings
    while (chunk_i < CHUNK_COUNT(msg_len)) {
        init_w_array(w_array, msg_buffer += chunk_i * CHUNK_SIZE);
        copy_buffers(internal_buffers, buffers, 8);
        run_sha256_internal_operations(internal_buffers, w_array);
        add_buffers(buffers, internal_buffers, 8);
        chunk_i++;
    }
}

char *sha256(const char *msg, size_t msg_len) {
	unsigned char *msg_buffer;
    t_8i_buffer buffers;

	if (!(msg_buffer = init_msg_buffer(msg, msg_len)))
		return (NULL);

    copy_buffers(buffers, default_sha256_buffers, 8);
    run_sha256_operations(buffers, msg_buffer, msg_len);
    free(msg_buffer);

	return (build_hash(buffers, 3, 256));
}
