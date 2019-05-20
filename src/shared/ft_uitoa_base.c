/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:50:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:37:55 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char*ft_uitoa_base(uintmax_t nb, intmax_t base, char letter)
{
    uintmax_t	temp;
    int		power;
    char	*str;

    temp	= nb;
    power	= 1;
    while (temp /= base)
        power++;
    if (!(str = ft_strnew(power)))
        return (NULL);

    while (power--)
    {
        if (nb % base >= 10)
            str[power] = nb % base - 10 + letter;
        else
            str[power] = nb % base + '0';
        nb /= base;
    }
    return (str);
}

char*ft_uitoa_base_len(uintmax_t nb, intmax_t base, char letter, int len)
{
    int		i;
    int		diff;
    char	*str;
    char	*new_str;

    i		= 0;
    str		= ft_uitoa_base(nb, base, letter);
    diff	= len - ft_strlen(str);

    if (diff > 0) {
        if (!(new_str = ft_strnew(len)))
            return (NULL);

        while (i < diff)
            new_str[i++] = '0';

        ft_strncpy(new_str + i, str, len - diff);
        free(str);

        return (new_str);
    }

    return (str);
}
