/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:11:58 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 18:14:07 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

typedef uint32_t    (*t_ops_1a)(uint32_t x);
typedef uint32_t    (*t_ops_buffer)(uint32_t *group);

typedef enum { FALSE, TRUE } bool;

typedef union           u_i_buffer {
    uint32_t	i;
    uint8_t	c[4];
}                       t_i_buffer;

typedef union           u_l_buffer {
    uint64_t	l;
    uint8_t	c[8];
}                       t_l_buffer;

typedef union           u_16i_buffer {
    uint32_t	i[16];
    uint8_t	c[64];
}                       t_16i_buffer;

typedef uint32_t	t_4_uint32[4];
typedef uint32_t	t_8_uint32[8];
typedef uint32_t	t_64_uint32[64];

uint32_t	invert_uint32(uint32_t x);
void		ft_buffer_assign_add(uint32_t *dst,
    const uint32_t *src,
    size_t length);
void ft_buffer_copy(uint32_t *dst,
    const uint32_t *src,
    size_t length);
unsigned char*ft_ssl_msg_padding(const char *msg,
    size_t msg_len,
    size_t new_len,
    bool is_little_endian);

uint32_t	ft_rotate_bits_left(uint32_t x, char rotations);
uint32_t	ft_rotate_bits_right(uint32_t x, char rotations);

char	*ft_uitoa_base(uintmax_t nb, intmax_t base, char letter);
char	*ft_uitoa_base_len(uintmax_t nb, intmax_t base, char letter,
    size_t len);

char*build_hash(uint32_t *buffers, size_t buffer_count,
    bool is_little_endian);

#endif
