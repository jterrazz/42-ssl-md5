/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:57:46 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:41:45 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
#define MD5_H

// Explainations: a chunk is 64 bits or 512 bits // A chunk is a 512 bits part
// of the buffer;
// https://crypto.stackexchange.com/questions/10829/why-initialize-sha1-with-specific-buffer
// Append 1 bit to the message + length so its 4 bits (int) + 4 bits (int)
// Test and compare with length from 0 to 512 + try sending empty files
// Take the wikipedia algorythm to explain
// MD5 uses a buffer that is made up of four words that are each 32 bits long =>
// 4 bytes => int

// TODO Use modulo ??? // Check placing the 1 in the middle
#define CHUNK_COUNT(msg_len) (1 + (msg_len + 8) / CHUNK_SIZE)
#define CHUNK_SIZE 64

#include "../shared/shared.h"
#include <stdlib.h>
#include <string.h>

extern const unsigned int	g_md5_shifts[64];
extern const unsigned int	g_computed_sines[64];
extern const t_8i_buffer	g_md5_default_buffers;

/*
** Prototypes
*/

char*md5(const char *msg, size_t msg_len);

/*
** Operations
*/

unsigned int	md5_op_shift_1(unsigned int buffers[]);
unsigned int	md5_op_shift_2(unsigned int buffers[]);
unsigned int	md5_op_shift_3(unsigned int buffers[]);
unsigned int	md5_op_shift_4(unsigned int buffers[]);

unsigned int	md5_op_g_1(unsigned int i);
unsigned int	md5_op_g_2(unsigned int i);
unsigned int	md5_op_g_3(unsigned int i);
unsigned int	md5_op_g_4(unsigned int i);
#endif
