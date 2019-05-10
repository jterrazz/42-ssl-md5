/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 15:09:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./cmd_dispatcher.h"

static int ft_ssl_error(int argc, char **argv) {
	if (argc < 2) {
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (EXIT_SUCCESS);
	}

	ft_printf("ft_ssl: Error: '%s' is an invalid command\n\n", argv[1]);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n");
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	return cmd_dispatcher(argc, argv) && ft_ssl_error(argc, argv);
}
