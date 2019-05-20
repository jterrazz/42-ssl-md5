/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:25 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:36:05 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_errno.h"
#include "./shared/shared.h"
#include "ft_printf.h"

t_ssl_error g_ft_ssl_error;

char *g_ssl_errors[] = {
    FOREACH_ERROR(GENERATE_STRING)
};

int ft_error(t_ssl_error error)
{
    g_ft_ssl_error = error;
    return (FAILURE);
}

char*ft_strerror(t_ssl_error error)
{
    return (g_ssl_errors[error]);
}
