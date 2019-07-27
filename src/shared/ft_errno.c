/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:41:25 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 13:48:40 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_errno.h"

t_ssl_error g_ft_ssl_error;

t_ssl_err_msg g_ssl_errors[] = {
	{ ERR_NO_ARG, "usage: ft_ssl command [command opts] [command args]" },
	{ ERR_NULL, "" }
};

static char	*ft_strerror(t_ssl_error error)
{
	t_ssl_err_msg *errs;

	errs = g_ssl_errors;
	while (errs)
	{
		if (error == errs->err)
			return (errs->message);
		errs += 1;
	}
	return (NULL);
}

int			ft_error(t_ssl_error error)
{
	g_ft_ssl_error = error;
	return (FAILURE);
}

int			ft_perror(void)
{
	if (g_ft_ssl_error == ERR_NO_MSG)
		return (FAILURE);
	else if (g_ft_ssl_error == ERR_ERRNO)
		ft_printf("%s", strerror(errno));
	else
		ft_printf("%s\n", ft_strerror(g_ft_ssl_error));
	return (FAILURE);
}
