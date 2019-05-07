/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:27:28 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 13:34:55 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha256.h"

unsigned int sha256_op_a(unsigned int x) {
	return ft_rotate_bits_right(x, 2) ^ ft_rotate_bits_right(x, 13) ^ ft_rotate_bits_right(x, 22);
}

unsigned int sha256_op_b(unsigned int x) {
	return ft_rotate_bits_right(x, 6) ^ ft_rotate_bits_right(x, 11) ^ ft_rotate_bits_right(x, 25);
}

unsigned int sha256_op_c(unsigned int x) {
	return ft_rotate_bits_right(x, 7) ^ ft_rotate_bits_right(x, 18) ^ (x >> 3);
}

unsigned int sha256_op_d(unsigned int x) {
	return ft_rotate_bits_right(x, 17) ^ ft_rotate_bits_right(x, 19) ^ (x >> 10);
}
