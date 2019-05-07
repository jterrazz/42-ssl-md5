/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:57:46 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 18:46:33 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define CHUNK_COUNT(msg_len) (1 + (msg_len + 8) / CHUNK_SIZE ) // TODO Use modulo ??? // Check placing the 1 in the middle
# define CHUNK_SIZE 64

// TODO REplace types by stdint.h ???

// TODO Secure the mallocs
# include <string.h> // TODO Check includes
# include <stdlib.h>
#include "../utils/utils.h"

typedef unsigned int	t_4i_buffer[4];
typedef unsigned int	(*t_bits_ops)(t_4i_buffer group); // Transform to generic types ? (unsigned)
typedef int	(*t_g_ops)(int i);

char *md5(const char *msg, size_t msg_len);

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
extern const t_8i_buffer	default_md5_buffers;
#endif
