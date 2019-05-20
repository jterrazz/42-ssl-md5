/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:57:46 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 19:31:51 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
#define MD5_H

#define MD5_CHUNK_SIZE 64
#define MD5_CHUNK_COUNT_FILLED(msg_len) ((msg_len + 1 + 8) / MD5_CHUNK_SIZE)
#define MD5_CHUNK_COUNT_PARTIAL(msg_len) ((msg_len + 1 + 8) % MD5_CHUNK_SIZE)
#define MD5_CHUNK_COUNT(msg_len) (MD5_CHUNK_COUNT_FILLED(msg_len) + \
                                  (MD5_CHUNK_COUNT_PARTIAL(msg_len) ? 1 : 0))

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
