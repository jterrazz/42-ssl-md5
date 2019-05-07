/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:35:31 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 18:45:34 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO Tranform all to unsigned

int md5_op_g_1(int i) {
    return i;
}

int md5_op_g_2(int i) {
    return (5 * i + 1) % 16;
}

int md5_op_g_3(int i) {
    return (3*i + 5) % 16;
}

int md5_op_g_4(int i) {
    return (7*i) % 16;
}
