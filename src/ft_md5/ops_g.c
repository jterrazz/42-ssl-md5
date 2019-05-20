/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:35:31 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:41:17 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int md5_op_g_1(unsigned int i)
{
    return (i);
}

unsigned int md5_op_g_2(unsigned int i)
{
    return ((5 * i + 1) % 16);
}

unsigned int md5_op_g_3(unsigned int i)
{
    return ((3 * i + 5) % 16);
}

unsigned int md5_op_g_4(unsigned int i)
{
    return ((7 * i) % 16);
}
