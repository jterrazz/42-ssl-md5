/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:25 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/19 20:34:31 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./common/common.h"
#include "ft_printf.h"
#include "./error.h"

t_ssl_error g_ft_ssl_error;

char *g_ssl_errors[] = {
    FOREACH_ERROR(GENERATE_STRING)
};

int ft_error(t_ssl_error error)
{
    g_ft_ssl_error = error;
    return (FAILURE);
}
char* ft_strerror(t_ssl_error error)
{
    return (g_ssl_errors[error]);
}
