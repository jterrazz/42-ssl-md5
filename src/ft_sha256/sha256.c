/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 13:15:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha256.h"
#include "libft.h"
#include "ft_printf.h" // TODO DElete

# define CHUNK_COUNT(msg_len) (1 + (msg_len + 8) / CHUNK_SIZE ) // TODO Use modulo ??? Use + 1 inside ?
// sha256_write(st, buf, 64 + 56 - (len % 64));
# define CHUNK_SIZE 64 // 512 bits
// TODO TRANSFERT IN A GLOBAL FUNCTION WITH THE SIZE_T CHANGE

// // Check with overflows ???
// final_length_buffer.l = 8 * msg_len; // Because it was set to 0, the size is % 2^64 ?????
// ft_memcpy(msg_buffer + cursor, final_length_buffer.c, 8);
// Test with big files where size goes more than 32 bits and compare in a .go file
// Secure all mallocs

// TODO Add consts everywhere
// TODO Check size_t is everwhere (also md5)
//(512 - ((m.length + 1 + 64) % 512))

// Convert all t_64i_buffer to ***t_64i_buffer

static void init_w_array(t_64i_buffer *w_array, unsigned char *msg_buffer) {
    int i;
    int j;

    for (i = 0, j = 0; i < 16; ++i, j += 4)
		w_array->i[i] = (msg_buffer[j] << 24) | (msg_buffer[j + 1] << 16) | (msg_buffer[j + 2] << 8) | (msg_buffer[j + 3]);
    i = 16;
    while (i < 64) {
        w_array->i[i] = sha256_op_d(w_array->i[i - 2]) + w_array->i[i - 7] + sha256_op_c(w_array->i[i - 15]) + w_array->i[i - 16];
        i++;
    }
}

// TODO Rename to transform in both
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

// Replace 8 by MACRO Nb of buffers
// Maybe make general ft for iteration in chunks
static void run_sha256_operations(t_8i_buffer buffers, unsigned char *msg_buffer, size_t msg_len) {
    size_t chunk_i;
    t_64i_buffer w_array;
    t_8i_buffer internal_buffers;
    // 16 mots de 4 bytes donc 16 unsigned int

    chunk_i = 0;
    // TODO Test with super long strings

    while (chunk_i < CHUNK_COUNT(msg_len)) {
        init_w_array(&w_array, msg_buffer += chunk_i * CHUNK_SIZE); // Check this addition is working with longer strings
        ft_buffer_copy(internal_buffers, buffers, 8);
        run_sha256_internal_operations(internal_buffers, w_array);
        ft_buffer_assign_add(buffers, internal_buffers, 8);
        chunk_i++;
    }
}

char *sha256(const char *msg, size_t msg_len) {
	unsigned char *msg_buffer;
    t_8i_buffer buffers;

	if (!(msg_buffer = ft_ssl_msg_padding(msg, msg_len, CHUNK_COUNT(msg_len) * CHUNK_SIZE, FALSE)))
		return (NULL);

    ft_buffer_copy(buffers, default_sha256_buffers, 8);
    run_sha256_operations(buffers, msg_buffer, msg_len);
    free(msg_buffer);

	return (build_hash(buffers, 8, FALSE));
}
