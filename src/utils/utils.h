/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:11:58 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/09 17:28:59 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

typedef union			u_i_buffer {
	unsigned int	i;
	unsigned char	c[4];
}						t_i_buffer;

typedef union			u_l_buffer {
	unsigned long	l;
	unsigned char	c[8];
}						t_l_buffer;

typedef unsigned int	t_8i_buffer[8]; // TODO Transofrm in both projects to union values // Remove in ft_sha256 too

typedef union			u_16i_buffer {
	unsigned int	i[16];
	unsigned char	c[64];
}						t_16i_buffer;

typedef union			u_64i_buffer {
	unsigned int	i[64];
	unsigned char	c[256];
}						t_64i_buffer;

void add_buffers(unsigned int *dst, const unsigned int *src, int length);
void copy_buffers(unsigned int *dst, const unsigned int *src, int length);

unsigned int ft_rotate_bits_left(unsigned int x, char rotations);
unsigned int ft_rotate_bits_right(unsigned int x, char rotations);

char	*ft_uitoa_base(uintmax_t nb, intmax_t base, char letter);
char	*ft_uitoa_base_len(uintmax_t nb, intmax_t base, char letter, size_t len);

char *build_hash(t_8i_buffer buffers, size_t buffer_count, int is_little_endian);

#endif
