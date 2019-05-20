/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:11:58 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:37:49 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

// TODO REplace types by stdint.h ???
// Replace unsigned int by buffer
#include <stdlib.h>

typedef unsigned int    (*t_ops_1a)(unsigned int x);
typedef unsigned int    (*t_ops_buffer)(unsigned int *group);

typedef enum { FALSE, TRUE } bool;

typedef union           u_i_buffer {
    unsigned int	i;
    unsigned char	c[4];
}                       t_i_buffer;

typedef union           u_l_buffer {
    unsigned long	l;
    unsigned char	c[8];
}                       t_l_buffer;

// TODO Remove unoin for not used ones and find better name
typedef unsigned int	t_4i_buffer[4];
typedef unsigned int	t_8i_buffer[8];

typedef union           u_16i_buffer {
    unsigned int	i[16];
    unsigned char	c[64];
}                       t_16i_buffer;

typedef union           u_64i_buffer {
    unsigned int	i[64];
    unsigned char	c[256];
}                       t_64i_buffer;

uint32_t	invert_uint32(uint32_t x);
void		ft_buffer_assign_add(unsigned int *dst,
    const unsigned int *src,
    size_t length);
void ft_buffer_copy(unsigned int *dst,
    const unsigned int *src,
    size_t length);
unsigned char*ft_ssl_msg_padding(const char *msg,
    size_t msg_len,
    size_t new_len,
    bool is_little_endian);

unsigned int	ft_rotate_bits_left(unsigned int x, char rotations);
unsigned int	ft_rotate_bits_right(unsigned int x, char rotations);

char	*ft_uitoa_base(uintmax_t nb, intmax_t base, char letter);
char	*ft_uitoa_base_len(uintmax_t nb, intmax_t base, char letter,
    size_t len);

char*build_hash(t_8i_buffer buffers, size_t buffer_count,
    bool is_little_endian);

#endif
