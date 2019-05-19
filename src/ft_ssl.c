/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/19 22:43:12 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./cmd.h"      // TODO Remove and delete .h if not used
#include "libft.h"      // Del ?
#include <stdlib.h>
#include <errno.h>
#include "./ft_errno.h"

// TODO Understand errors.h
 // Test with last arg is s

 // Choose a -ssssss string comportment
 // make && ./a.out md5 -s arg1 -sss arg2 -s arg3

// Print this error:
// ft_printf("ft_ssl: %s: %s: No such file or directory\n",
//     cmd.cmd,
//     state->input_files[i]);


// Add this
// 42-ssl-md5 git:(master) ✗ md5 -j
// md5: illegal option -- j
// usage: md5 [-pqrtx] [-s string] [files ...]

// Test all errors in go
// Compare errors to https://github.com/psprawka/Ft_ssl/blob/master/srcs/get.c
// TODO Do error handling probably with 1 GLOBAL (Check if that's usefull
// probably not)
// Replace exit success by number ?
// Delete get_next_line ?
// If only "-" without any flag ?
// md5 -s -r -rs -r
// TODO Do on 1 -
// Consider multiple -s
// md5 -s "do" -d Makefile
// md5 -s "do" -dd -s "do"  Makef
// ft_ssl: md5: -s: No such file or directory

// TODO Do global error handling and in .go file test for all error cases

// TODO Error in global variable
// Replace all by SUCCESS or FAILURE
// Go over buffer for FDs

// FD 0 with no arg = "" ou si touch file sans rien
// a.out md5 sans rien
// Open a folder should print a message (shoudl continue )

// Handle a wrong flag return
// Check it compares the return and not rhe -= result in => if (( d -= dd) > x)
// ./a.out md5 - y

static int ft_ssl_error(int argc, char **argv)
{
    if (g_ft_ssl_error == ERR_INVALID_CMD) { // TODO Find a way to build errors str in global ?
        ft_printf("ft_ssl: Error: '%s' is an invalid command\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:\n", argv[1]);
    } else if (g_ft_ssl_error == ERR_ERRNO) {
        ft_printf("%s", strerror(errno)); // TODO Check that
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
