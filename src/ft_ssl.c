/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/06 11:18:18 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h" // TODO Remove and delete .h if not used
#include "libft.h"
#include "ft_printf.h"

// TODO Adapt and add printf with libft

int main(int argc, char **argv) {
	if (argc < 2) {
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return 0;
	}

	if (!ft_strncmp(argv[1], "md5", 3))
		ft_md5(argc, argv);
	else if (!ft_strncmp(argv[1], "sha256", 6))
		ft_sha256(argc, argv);
	else {
		ft_printf("ft_ssl: Error: 'foobar' is an invalid command\n\n");
		ft_printf("Standard commands:\n\n");
		ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
		ft_printf("Cipher commands:\n");
	}
	return 0;
}
