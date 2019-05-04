/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:16:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/04 18:19:33 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_rotate_bits_left(unsigned int x, char rotations) {
    return ((x << rotations) | (x >> (32 - rotations)));
}
