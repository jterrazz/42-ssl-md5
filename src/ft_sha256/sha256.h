/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:42:04 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "../shared/shared.h"

# define SHA256_C_SIZE 64
# define S(len) ((len + 1 + 8 + DEC(SHA256_C_SIZE)) & ~DEC(SHA256_C_SIZE))
# define SHA256_CHUNK_COUNT(len) (S(len) / SHA256_C_SIZE)

/*
** Globals
*/

extern const uint32_t	g_sha256_k[64];
extern const uint32_t	g_sha256_default_buffers[8];

/*
** Prototypes
*/

char		*ft_sha256(const char *msg, size_t msg_len);

void		sha256_init_w_array(t_64_uint32 w_array,
	unsigned char *formatted_msg);
void		sha256_shuffle_buffers(t_8_uint32 buffers,
	t_64_uint32 w_array);
void		sha256_run_ops(t_8_uint32 buffers,
	unsigned char *formatted_msg, size_t msg_len);

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
