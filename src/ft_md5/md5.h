/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:57:46 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/05 00:47:17 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define CHUNK_SIZE 64
# define HASH_SIZE 32 // 128 / 8 = 16 bytes represented with 32 hexadecimal letters

// TODO REplace types by stdint.h ???

// TODO Secure the mallocs
# include <string.h> // TODO Check includes
# include <stdlib.h>
#include "../utils/utils.h"

typedef union			u_int_buffer {
	unsigned int	i;
	unsigned char	c[4];
}						t_int_buffer;

typedef union			u_chunk_buffer {
	unsigned int	i[16];
	unsigned char	c[64];
}						t_chunk_buffer;

typedef unsigned int	t_buffer_group[4];
typedef unsigned int	(*t_bits_ops)(t_buffer_group group);
typedef int	(*t_g_ops)(int i);

char *md5(const char *msg, size_t msg_len);

/*
** Internal functions
*/

void add_buffers(t_buffer_group dst, t_buffer_group src, int length);
void copy_buffers(t_buffer_group dst, t_buffer_group src, int length);

/*
** Operations
*/

unsigned int md5_op_shift_1(unsigned int buffers[]);
unsigned int md5_op_shift_2(unsigned int buffers[]);
unsigned int md5_op_shift_3(unsigned int buffers[]);
unsigned int md5_op_shift_4(unsigned int buffers[]);

int md5_op_g_1(int i);
int md5_op_g_2(int i);
int md5_op_g_3(int i);
int md5_op_g_4(int i);

/*
** Constants
*/

extern const unsigned int g_bits_shift_amount[64];
extern const unsigned int g_computed_sines[64];

#endif
