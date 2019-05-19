/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/19 23:34:31 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
#define SHA256_H

#include "../shared/shared.h"

# define CHUNK_COUNT(msg_len) (1 + (msg_len + 8) / CHUNK_SIZE ) // TODO Use modulo ??? Use + 1 inside ?
// sha256_write(st, buf, 64 + 56 - (len % 64));
//(512 - ((m.length + 1 + 64) % 512))
# define CHUNK_SIZE 64

extern const unsigned int g_sha256_k[64];
extern const unsigned int g_sha256_default_buffers[8];

/*
** Prototypes
*/

char *sha256(const char *msg, size_t msg_len);

/*
** Operations
*/

unsigned int sha256_op_a(unsigned int x);
unsigned int sha256_op_b(unsigned int x);
unsigned int sha256_op_c(unsigned int x);
unsigned int sha256_op_d(unsigned int x);
unsigned int sha256_op_ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int sha256_op_maj(unsigned int x, unsigned int y, unsigned int z);

#endif
