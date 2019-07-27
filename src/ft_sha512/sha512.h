/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:25:41 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:46:02 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H

# include "../shared/shared.h"
# include "../ft_sha256/sha256.h"

# define SHA512_CS 128
# define SHA512_CS(len) ((len + 1 + 8 + DEC(SHA512_CS)) & ~DEC(SHA512_CS))
# define SHA512_CHUNK_COUNT(len) (SHA512_CS(len) / SHA512_CS)

/*
** Globals
*/

extern const uint64_t	g_sha512_k[80];
extern const uint64_t	g_sha512_default_buffers[8];

/*
** Prototypes
*/

char		*ft_sha512(const char *msg, size_t msg_len);

void		sha512_init_w_array(t_80_uint64 w_array,
	unsigned char *formatted_msg);
void		sha512_shuffle_buffers(t_8_uint64 buffers,
	t_80_uint64 w_array);
void		sha512_run_ops(t_8_uint64 buffers,
	unsigned char *formatted_msg, size_t msg_len);


/*
** Operations
*/

uint64_t	sha512_op_a(uint64_t x);
uint64_t	sha512_op_b(uint64_t x);
uint64_t	sha512_op_c(uint64_t x);
uint64_t	sha512_op_d(uint64_t x);
uint64_t	sha512_op_ch(uint64_t x, uint64_t y, uint64_t z);
uint64_t	sha512_op_maj(uint64_t x, uint64_t y, uint64_t z);


#endif
