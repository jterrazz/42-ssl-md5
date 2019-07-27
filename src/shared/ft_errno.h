/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:23 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 13:50:41 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# include "./shared.h"

# define FAILURE -1
# define SUCCESS 0

typedef enum		e_ssl_error {
	ERR_NULL,
	ERR_NO_MSG,
	ERR_ERRNO,
	ERR_NO_ARG
}					t_ssl_error;

typedef struct		s_ssl_err_msg {
	t_ssl_error		err;
	char			message[100];
}					t_ssl_err_msg;

int					ft_error(t_ssl_error error);
int					ft_perror(void);

extern t_ssl_error g_ft_ssl_error;

#endif
