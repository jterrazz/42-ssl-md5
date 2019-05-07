/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:27:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/06 12:05:23 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int sha256_op_ch(unsigned int x, unsigned int y, unsigned int z) {
	return (x & y) ^ (~x & z);
}

unsigned int sha256_op_maj(unsigned int x, unsigned int y, unsigned int z) {
	return (x & y) ^ (x & z) ^ (y & z);
}
