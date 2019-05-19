/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:23 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/19 20:32:56 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

// TODO Understand errors
#define FOREACH_ERROR(ERROR) \
    ERROR(ERR_NO_ARG)        \
    ERROR(ERR_OPEN_FAIL)     \
    ERROR(ERR_CLOSE_FAIL)    \
    ERROR(ERR_MALLOC_FAIL)   \
    ERROR(ERR_S_FLAG_NO_ARG)

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) # STRING,

typedef enum e_ssl_error {
    FOREACH_ERROR(GENERATE_ENUM)
} t_ssl_error;

int	ft_error(t_ssl_error error);
char	* ft_strerror(t_ssl_error error);

#endif
