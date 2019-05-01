/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:41:04 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/01 16:50:47 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

// #include "libft.h"

typedef union			u_buffer {
	unsigned int	i;
	unsigned char	c[4];
}						t_buffer;

typedef unsigned int	t_buffer_digest[4];

unsigned int md5_op_1(t_buffer_digest digest[]);
unsigned int md5_op_2(t_buffer_digest digest[]);
unsigned int md5_op_3(t_buffer_digest digest[]);
unsigned int md5_op_4(t_buffer_digest digest[]);

#endif
