/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:25:41 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:15:59 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
#define SHA512_H

#include "../shared/shared.h"
#include "../ft_sha256/sha256.h"

#define SHA512_CHUNK_SIZE 128
#define SHA512_CHUNKS_SIZE(len) ((len + 1 + 8 + DEC(SHA512_CHUNK_SIZE)) & ~DEC(SHA512_CHUNK_SIZE))
#define SHA512_CHUNK_COUNT(len) (SHA512_CHUNKS_SIZE(len) / SHA512_CHUNK_SIZE)

/*
** Globals
*/

extern const uint64_t	g_sha512_k[64];
extern const uint64_t	g_sha512_default_buffers[8];

/*
** Prototypes
*/

char *ft_sha512(const char *msg, size_t msg_len);

/*
** Operations
*/

uint64_t sha512_op_a(uint64_t x);
uint64_t sha512_op_b(uint64_t x);
uint64_t sha512_op_c(uint64_t x);
uint64_t sha512_op_d(uint64_t x);
uint64_t sha512_op_ch(uint64_t x, uint64_t y, uint64_t z);
uint64_t sha512_op_maj(uint64_t x, uint64_t y, uint64_t z);


#endif
