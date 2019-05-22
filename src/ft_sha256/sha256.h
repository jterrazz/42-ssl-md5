/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 18:08:09 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
#define SHA256_H

#define SHA256_CHUNK_SIZE 64
#define SHA256_CHUNK_COUNT_FILLED(msg_len) ((msg_len + 1 + 8) / \
                                            SHA256_CHUNK_SIZE)
#define SHA256_CHUNK_COUNT_PARTIAL(msg_len) ((msg_len + 1 + 8) % \
                                             SHA256_CHUNK_SIZE)
#define SHA256_CHUNK_COUNT(msg_len) (SHA256_CHUNK_COUNT_FILLED(msg_len) +       \
                                     (SHA256_CHUNK_COUNT_PARTIAL(msg_len) ? 1 : \
                                      0))

#include "../shared/shared.h"

/*
** Globals
*/

extern const uint32_t	g_sha256_k[64];
extern const uint32_t	g_sha256_default_buffers[8];

/*
** Prototypes
*/

char*sha256(const char *msg, size_t msg_len);

/*
** Operations
*/

uint32_t	sha256_op_a(uint32_t x);
uint32_t	sha256_op_b(uint32_t x);
uint32_t	sha256_op_c(uint32_t x);
uint32_t	sha256_op_d(uint32_t x);
uint32_t	sha256_op_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t	sha256_op_maj(uint32_t x, uint32_t y, uint32_t z);

#endif
