/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:42:40 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd/cmd.h"
#include "./ft_errno.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

// TODO REplace types by stdint.h ???
// Replace unsigned int by buffer

static int ft_ssl(int argc, char **argv)
{
    int		i;
    t_cmd_state state;

    i = 0;
    if (argc < 2) {
        ft_error(ERR_NO_ARG);
        return (FAILURE);
    }

    while (g_cmds[i].cmd) {
        if (!ft_strcmp(g_cmds[i].cmd,
            argv[1])) return (cmd_init_state(&state, argc,
            argv, &g_cmds[i]) || cmd_run(g_cmds[i], &state) ||
                              cmd_clean(&state));

        i++;
    }

    ft_printf(
        "ft_ssl: Error: '%s' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:\n",
        argv[1]);
    return (ft_error(ERR_NO_MSG));
}

int main(int argc, char **argv)
{
    return (ft_ssl(argc, argv) && ft_perror());
}
