/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:04:15 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:16:30 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"

t_cmd g_cmds[] = {
	{ "md5", "MD5", &ft_md5, "usage: md5 [-pqrs] [-s string] [files ...]" },
	{ "sha256", "SHA256", &ft_sha256,
		"usage: sha256 [-pqrs] [-s string] [files ...]" },
	{ "sha512", "SHA512", &ft_sha512,
		"usage: sha512 [-pqrs] [-s string] [files ...]" },
	{ "sha384", "SHA384", &ft_sha384,
		"usage: sha384 [-pqrs] [-s string] [files ...]" },
	{ "sha224", "SHA224", &ft_sha224,
		"usage: sha224 [-pqrs] [-s string] [files ...]" },
	{ "sha1", "SHA1", &ft_sha1, "usage: sha1 [-pqrs] [-s string] [files ...]" },
	{ 0, 0, 0, 0 }
};

t_flag g_cmd_flags[] = {
	{ 'p', NULL, 0 },
	{ 'q', NULL, 0 },
	{ 'r', NULL, 0 },
	{ 's', &cmd_flag_s_handler, 1 },
	{ 0, 0, 0 }
};
