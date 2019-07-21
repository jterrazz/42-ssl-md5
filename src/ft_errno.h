/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:23 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:29:30 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include "./shared/shared.h"

#define FAILURE -1
#define SUCCESS 0

#define FOREACH_ERROR(ERROR) \
    ERROR(ERR_NO_MSG, "")    \
    ERROR(ERR_ERRNO, "")     \
    ERROR(ERR_NO_ARG, "usage: ft_ssl command [command opts] [command args]")

#define GENERATE_ENUM(ENUM, STRING) ENUM,
#define GENERATE_STRING(ENUM, STRING) STRING,

typedef enum e_ssl_error {
    FOREACH_ERROR(GENERATE_ENUM)
} t_ssl_error;

int	ft_error(t_ssl_error error);
int	ft_perror();

extern t_ssl_error g_ft_ssl_error;

#endif
