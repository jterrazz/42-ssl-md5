/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:04:15 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 16:56:00 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dispatch.h"
#include "./ft_md5/md5.h"
#include "./ft_sha256/sha256.h"

const t_cmd g_cmds[] = {
	{ "md5", &md5 },
	{ "sha256", &sha256 },
	{ 0, 0 }
};

const t_flag g_common_flags[] = {
	{ "p", p_flags_handler, 0 },
	{ "q", NULL, 0 },
	{ "r", NULL, 0 },
	{ "s", NULL, 1 },
	{ 0, 0, 0 }
};
