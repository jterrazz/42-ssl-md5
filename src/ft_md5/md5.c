/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:55:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/05 13:35:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"// Delte
#include "stdio.h"// Delte
#include "ft_printf.h"// Delte
#include "./md5.h"// Delte

// Explainations: a chunk is 64 bits or 512 bits // A chunk is a 512 bits part of the buffer;
// Create debugger to show author, all includes, check all functions called
// https://crypto.stackexchange.com/questions/10829/why-initialize-sha1-with-specific-buffer
// Append 1 bit to the message + length so its 4 bits (int) + 4 bits (int)
// Test and compare with length from 0 to 512 + try sending empty files

t_buffer_group default_buffers = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 }; // Better placement

char *md5(const char *msg, size_t msg_len) {
    static t_bits_ops ft_f[4] = { &md5_op_shift_1, &md5_op_shift_2, &md5_op_shift_3, &md5_op_shift_4 };
    static t_g_ops ft_g[4] = { &md5_op_g_1, &md5_op_g_2, &md5_op_g_3, &md5_op_g_4 };

    int i = 0;
    int chunk_number;
    int buffer_cursor = 0;

    chunk_number = (1 + (msg_len + 8) / CHUNK_SIZE ); // TODO Use modulo ???
    unsigned char *msg_buffer = malloc(chunk_number * CHUNK_SIZE);
    if (!msg_buffer)
        return NULL;


    ft_memcpy(msg_buffer, msg, msg_len);
    msg_buffer[msg_len] = 0b10000000;

    buffer_cursor = msg_len + 1;
    while (buffer_cursor < chunk_number * CHUNK_SIZE) { // TODO Transform to a buffer_cursor
        msg_buffer[buffer_cursor] = 0;
        buffer_cursor++;
    }
    buffer_cursor -= 8; // Because we add '0' with => bits ≡ 448 (mod 512)
    t_int_buffer size_buffer;
    size_buffer.i = 8 * msg_len; // Because it was set to 0, the size is % 2^64 ?????
    ft_memcpy(msg_buffer + buffer_cursor, size_buffer.c, 4);

    // Now we will process each chunk of 512 bits
    int chunk_i = 0;
    t_chunk_buffer chunk;
    t_buffer_group tmp_buffers; // MD5 uses a buffer that is made up of four words that are each 32 bits long => 4 bytes => int
    t_buffer_group buffers;

    copy_buffers(buffers, default_buffers, 4);

    t_bits_ops f;
    t_g_ops g;
    int f_result; // Take the wikipedia algorythm to explain

    while (chunk_i < chunk_number) {
        ft_memcpy(chunk.c, msg_buffer + chunk_i * CHUNK_SIZE, CHUNK_SIZE);
        i = 0;

        copy_buffers(tmp_buffers, buffers, 4);

        while (i < 64) {
            g = ft_g[i / 16];
            f = ft_f[i / 16];
            f_result = f(tmp_buffers) + tmp_buffers[0] + g_computed_sines[i] + chunk.i[g(i)];
            tmp_buffers[0] = tmp_buffers[3];
            tmp_buffers[3] = tmp_buffers[2];
            tmp_buffers[2] = tmp_buffers[1];
            tmp_buffers[1] = tmp_buffers[1] + ft_rotate_bits_left(f_result, g_bits_shift_amount[i]);
            i++;
        }

        add_buffers(buffers, tmp_buffers, 4);
        chunk_i++;
    }

    free(msg_buffer);
    char *hash = ft_strnew(HASH_SIZE + 2);
    if (!hash)
        return (NULL);
    hash[0] = '0';
    hash[1] = 'x';
    t_int_buffer print_buffer;
    int j;
    i = 0;

    while (i < 4) {
        print_buffer.i = buffers[i];
        j = 0;
        while (j < 4) {
            char *hash_part = ft_uitoa_base_len(print_buffer.c[j], 16, 'a', 2);
            if (!hash_part)
                return (NULL);
            ft_strncpy(hash + 2 + j * 2 + (i * (HASH_SIZE / 4)), hash_part, HASH_SIZE / 4); // j * 2 = because we print 2 caracters per byte ; + 2 because of 0x; (i * (HASH_SIZE / 4)) for each buffer
            free(hash_part);

            j++;
        }
        i++;
    }
    return (hash);
}

// TODO Check what upper of lower case to use
