/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 19:34:51 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
#define SHA256_H

#include "../shared/shared.h"

#define SHA256_CHUNK_SIZE 64
#define SHA256_CHUNK_COUNT_FILLED(msg_len) ((msg_len + 1 + 8) / \
                                            SHA256_CHUNK_SIZE)
#define SHA256_CHUNK_COUNT_PARTIAL(msg_len) ((msg_len + 1 + 8) % \
                                             SHA256_CHUNK_SIZE)
#define SHA256_CHUNK_COUNT(msg_len) (SHA256_CHUNK_COUNT_FILLED(msg_len) +       \
                                     (SHA256_CHUNK_COUNT_PARTIAL(msg_len) ? 1 : \
                                      0))

extern const unsigned int	g_sha256_k[64];
extern const unsigned int	g_sha256_default_buffers[8];

/*
** Prototypes
*/

char*sha256(const char *msg, size_t msg_len);

/*
** Operations
*/

unsigned int	sha256_op_a(unsigned int x);
unsigned int	sha256_op_b(unsigned int x);
unsigned int	sha256_op_c(unsigned int x);
unsigned int	sha256_op_d(unsigned int x);
unsigned int	sha256_op_ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int	sha256_op_maj(unsigned int x, unsigned int y, unsigned int z);

#endif
