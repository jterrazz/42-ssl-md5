/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:23 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/19 22:07:37 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#define FOREACH_ERROR(ERROR)                                                 \
    ERROR(ERR_NO_ARG, "usage: ft_ssl command [command opts] [command args]") \
    ERROR(ERR_INVALID_CMD, "")                                               \
    ERROR(ERR_ERRNO, "")                                                     \
    ERROR(ERR_WRONG_FLAG, "")                                                \
    ERROR(ERR_S_FLAG_NO_ARG, "md5: option requires an argument -- s\nusage: md5 [-pqrtx] [-s string] [files ...]")

#define GENERATE_ENUM(ENUM, STRING) ENUM,
#define GENERATE_STRING(ENUM, STRING) STRING,

typedef enum e_ssl_error {
    FOREACH_ERROR(GENERATE_ENUM)
} t_ssl_error;

int	ft_error(t_ssl_error error);
char	* ft_strerror(t_ssl_error error);

extern t_ssl_error g_ft_ssl_error;

#endif  /* ifndef ERROR_H */
