/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 13:25:17 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
#define SHA256_H

#include "../utils/utils.h"

typedef unsigned int	t_8i_buffer[8]; // TODO Transofrm in both projects to union values

typedef unsigned int	(*t_ops_rot)(unsigned int x);
typedef unsigned int	(*t_ops_bits)(unsigned int x, unsigned int y, unsigned int z);

extern const unsigned int g_k[64];
extern const unsigned int default_sha256_buffers[8];

char *sha256(const char *msg, size_t msg_len);

unsigned int sha256_op_a(unsigned int x);
unsigned int sha256_op_b(unsigned int x);
unsigned int sha256_op_c(unsigned int x);
unsigned int sha256_op_d(unsigned int x);
unsigned int sha256_op_ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int sha256_op_maj(unsigned int x, unsigned int y, unsigned int z);
#endif
