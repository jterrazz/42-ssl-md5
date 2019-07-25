/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:25 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/25 21:05:19 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_errno.h"

// remove from extern ?
t_ssl_error g_ft_ssl_error; // ???

char *g_ssl_errors[] = {
    FOREACH_ERROR(GENERATE_STRING)
};

static char*ft_strerror(t_ssl_error error)
{
    return (g_ssl_errors[error]);
}

int ft_error(t_ssl_error error)
{
    g_ft_ssl_error = error;
    return (FAILURE);
}

int ft_perror()
{
    if (g_ft_ssl_error == ERR_NO_MSG) {
        return (FAILURE);
    } else if (g_ft_ssl_error == ERR_ERRNO) {
        ft_printf("%s", strerror(errno));
    } else {
        ft_printf("%s\n", ft_strerror(g_ft_ssl_error));
    }
    return (FAILURE);
}
