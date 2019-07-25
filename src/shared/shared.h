/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:11:58 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/26 00:11:35 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

// 2 more bonus and puts bonus in little tests

#define DEC(x) (x - 1)

#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "ft_printf.h"
#include "libft.h"
#include "./ft_errno.h"

typedef uint32_t    (*t_ops_1a)(uint32_t x);
typedef uint32_t    (*t_ops_buffer)(uint32_t *group);

typedef enum { FALSE, TRUE } bool;

typedef uint32_t	t_4_uint32[4];
typedef uint32_t	t_8_uint32[8];
typedef uint64_t	t_8_uint64[8];
typedef uint32_t	t_16_uint32[16];
typedef uint32_t	t_64_uint32[64];
typedef uint64_t	t_80_uint32[80];
typedef uint64_t	t_80_uint64[80];

/*
** Common algorithm methods
*/

unsigned char*build_msg(const char *msg, size_t msg_len,
    size_t formatted_msg_len, bool is_little_endian);

char*build_hash(uint32_t *buffers, size_t buffer_count, bool is_little_endian);
char*build_hash_64(uint64_t *buffers, size_t buffer_count, bool is_little_endian);

/*
** Utils
*/

uint64_t	ft_bswap_uint64(uint64_t x);
uint32_t	ft_bswap_uint32(uint32_t x);

void ft_uint32_arr_assign_add(uint32_t *dst, const uint32_t *src, size_t len);
void ft_uint32_arr_cpy(uint32_t *dst, const uint32_t *src, size_t len);
void ft_uint64_arr_assign_add(uint64_t *dst, const uint64_t *src, size_t len);
void ft_uint64_arr_cpy(uint64_t *dst, const uint64_t *src, size_t len);

uint32_t	ft_brotate_left(uint32_t x, char rotations);
uint32_t	ft_brotate_right(uint32_t x, char rotations);
uint64_t ft_brotate_right_64(uint64_t x, char rotations);

char	*ft_uitoa_base(uintmax_t nb, intmax_t base, char letter);
char	*ft_uitoa_base_len(uintmax_t nb, intmax_t base, char letter, size_t len);

#endif
