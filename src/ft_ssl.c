/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/01 16:36:04 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

// TODO Adapt and add printf with libft

int main(int argc, char **argv) {
	if (argc < 2)
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");

	if (!ft_strncmp(argv[1], "md5", 3))
		ft_md5(argc, argv);
	else {
		ft_putstr("ft_ssl: Error: 'foobar' is an invalid command\n\n");
		ft_putstr("Standard commands:\n\n");
		ft_putstr("Message Digest commands:\nmd5\nsha256\n\n");
		ft_putstr("Cipher commands:\n");
	}
	return 0;
}
