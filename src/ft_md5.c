/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:12:56 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/01 19:00:18 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

int *md5() {
    static t_buffer_digest digest = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    const static operations[4] = { &md5_op_1, &md5_op_2, &md5_op_3, &md5_op_4 };


}

void ft_md5(int argc, char **argv) {

}
