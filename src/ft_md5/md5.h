/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:57:46 by jterrazz          #+#    #+#             */
/*   Updated: 2019/06/07 15:35:46 by jterrazz         ###   ########.fr       */
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

/*
** Globals
*/

extern const uint32_t	g_md5_shifts[64];
extern const uint32_t	g_computed_sines[64];
extern const t_4_uint32 g_md5_default_buffers;

/*
** Prototypes
*/

char*ft_md5(const char *msg, size_t msg_len);

/*
** Operations
*/

uint32_t	md5_op_shift_1(uint32_t buffers[]);
uint32_t	md5_op_shift_2(uint32_t buffers[]);
uint32_t	md5_op_shift_3(uint32_t buffers[]);
uint32_t	md5_op_shift_4(uint32_t buffers[]);

uint32_t	md5_op_g_1(uint32_t i);
uint32_t	md5_op_g_2(uint32_t i);
uint32_t	md5_op_g_3(uint32_t i);
uint32_t	md5_op_g_4(uint32_t i);

#endif
