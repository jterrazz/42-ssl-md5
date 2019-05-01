/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:15:32 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/01 16:50:09 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

unsigned int md5_op_1(t_buffer_digest digest[]) {
    return ((digest[1] & digest[2]) | (~digest[1] & digest[3]));
}

unsigned int md5_op_2(t_buffer_digest digest[]) {
    return ((digest[1] & digest[3]) | (digest[2] & ~digest[3]));
}

unsigned int md5_op_3(t_buffer_digest digest[]) {
    return (digest[1] ^ digest[2] ^ digest[3]);
}

unsigned int md5_op_4(t_buffer_digest digest[]) {
    return (digest[2] ^ (digest[1] | ~digest[3]));
}
