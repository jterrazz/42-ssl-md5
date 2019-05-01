/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:27:25 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/01 17:54:12 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double pow(double x, double y) {
    double tmp;

    if (y == 0)
        return 1;
    tmp = pow(x, y / 2);

    if (y % 2 == 0)
        return temp * temp;
    else if (y > 0)
        return x * temp * temp;
    else
        return temp * temp / x;
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
