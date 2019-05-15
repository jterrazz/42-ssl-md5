/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/15 16:59:23 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"
#include "./cmd.h" // TODO Remove and delete .h if not used
#include "libft.h" // Del ?
#include <stdlib.h>

// Compare errors to https://github.com/psprawka/Ft_ssl/blob/master/srcs/get.c
// TODO Do error handling probably with 1 GLOBAL (Check if that's usefull
// probably not)
// Replace exit success by number ?

// md5 -s -r -rs -r
// TODO Do on 1 -
// Consider multiple -s
// md5 -s "do" -d Makefile
// md5 -s "do" -dd -s "do"  Makef

// TODO Do global error handling and in .go file test for all error cases

// TODO Error in global variable
static int ft_ssl_error(int argc, char **argv)
{
  if (argc < 2) {
    ft_printf(
      "usage: ft_ssl command [command opts] [command args]\n");
    return SUCCESS;
  }

  ft_printf("ft_ssl: Error: '%s' is an invalid command\n\n", argv[1]);
  ft_printf("Standard commands:\n\n");
  ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
  ft_printf("Cipher commands:\n");
  return SUCCESS;
}

static int ft_ssl(int argc, char **argv)
{
  int i;
  t_cmd_state state;

  i = 0;

  if (argc < 2) return FAILURE;

  while (g_cmds[i].cmd) {
    if (!ft_strcmp(g_cmds[i].cmd, argv[1])) return set_cmd_state(&state,
                                                                 argc,
                                                                 argv) ||
             cmd_run(
        g_cmds[i], &state);

    i++;
  }

  return FAILURE;
}

int main(int argc, char **argv)
{
  return ft_ssl(argc, argv) && ft_ssl_error(argc, argv);
}
