/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/25 23:57:54 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd/cmd.h"

static int usage(char **argv)
{
    ft_printf(
        "ft_ssl: Error: '%s' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha224\nsha256\nsha384\nsha512\n\nCipher commands:\n",
        argv[1]);
    return (FAILURE);
}

static int  interactive_interface(char **argv)
{
    char buffer[50];
    int i;
    t_file	*file;
    char	*hash;

    while (1)
    {
        i = 0;
        ft_printf("<./ft_ssl> ");
        fgets(buffer, 49, stdin);
        buffer[ft_strlen(buffer) - 1] = 0;
        while (g_cmds[i].cmd)
        {
            if (!ft_strcmp(g_cmds[i].cmd, buffer))
            {
                if (!(file = read_fd_content(0)) || !(hash = g_cmds[i].handler(file->data, file->length)))
                    return (FAILURE);
                free_file(file);
                ft_printf("\n%s\n", hash);
                free(hash);
                return (SUCCESS);
            }
            i++;
        }
        usage(argv);
    }
}

static int ft_ssl(int argc, char **argv)
{
    int		i;
    t_cmd_state state;

    i = 0;
    if (argc < 2)
        return (ft_error(ERR_NO_ARG));

    if (!ft_strcmp(argv[1], "-i"))
        return (interactive_interface(argv));

    while (g_cmds[i].cmd)
    {
        if (!ft_strcmp(g_cmds[i].cmd, argv[1]))
            return (cmd_init_state(&state, argc, argv, &g_cmds[i])
                || cmd_run(g_cmds[i], &state) || cmd_clean(&state));
        i++;
    }

    return (usage(argv));
}

int main(int argc, char **argv)
{
    return (ft_ssl(argc, argv) && ft_perror());
}
