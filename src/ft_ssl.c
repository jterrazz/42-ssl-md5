/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/21 19:37:03 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "./cmd/cmd.h"
#include "./ft_errno.h"
#include "ft_printf.h"
#include "libft.h"

// TODO REplace types by stdint.h ???
// Replace unsigned int by buffer
// Replace by size_t everywhere
// TODO Add -r index, and apply it from here

static int ft_ssl_error(int argc, char **argv)
{
    if (g_ft_ssl_error == ERR_INVALID_CMD) {    // TODO Find a way to build
                                                // errors str in global ?
        if (argc > 1)
        ft_printf(
            "ft_ssl: Error: '%s' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:\n",
            argv[1]);
    } else if (g_ft_ssl_error == ERR_ERRNO) {
        ft_printf("%s", strerror(errno));
    } else if (g_ft_ssl_error == ERR_WRONG_FLAG) {
        ft_printf("md5: illegal option -- j\nusage: md5 [-pqrtx] [-s string] [files ...]\n", strerror(errno)); // TODO Set the global error message with param (replace -j)
    } else {
        ft_printf("%s\n", ft_strerror(g_ft_ssl_error));
    }
    return (FAILURE);
}

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
            argv) || cmd_run(g_cmds[i], &state) || cmd_clean(&state));

        i++;
    }

    ft_error(ERR_INVALID_CMD);
    return (FAILURE);
}

int main(int argc, char **argv)
{
    return (ft_ssl(argc, argv) && ft_ssl_error(argc, argv));
}
