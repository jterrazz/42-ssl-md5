/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:27:25 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/02 14:47:46 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double ft_pow(double x, int y) {
    double tmp;

    if (y == 0)
        return 1;
    tmp = ft_pow(x, y / 2);

    if (y % 2 == 0)
        return tmp * tmp;
    else if (y > 0)
        return x * tmp * tmp;
    return tmp * tmp / x;
}

/*
Explain on the README.md
2
5 ======== 2 ======== 1 ======= 0
                                 1
                  2 * 1 * 1
        2 * 2 * 2
8 * 8
*/
