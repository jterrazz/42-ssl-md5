/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:34:20 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/22 17:23:07 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "ft_printf.h"
#include "libft.h"

int cmd_flag_s_handler(t_cmd_state *state, int argc_i)
{
    char **old_s_argv;
    if (argc_i + 1 >= state->argc) {
        if (state->cmd)
            ft_printf("%s: option requires an argument -- s\n%s\n",
                state->cmd->cmd,
                state->cmd->usage);
        return (ft_error(ERR_NO_MSG));
    }

    old_s_argv = state->s_argv;
    if (!(state->s_argv = malloc((state->s_argc + 1) * sizeof(char *)))) {
        return (ft_error(ERR_ERRNO));
    }
    ft_memmove(state->s_argv, old_s_argv, state->s_argc * sizeof(char *));
    free(old_s_argv);
    state->s_argv[state->s_argc]	= state->argv[argc_i + 1];
    state->s_argc			+= 1;

    return (SUCCESS);
}

void cmd_activate_flag(t_cmd_state *state, char flag)
{
    if (flag == 'p') {
        state->p = TRUE;
    } else if (flag == 'q') {
        state->q = TRUE;
    } else if (flag == 'r') {
        state->r = TRUE;
    } else if (flag == 's') {
        state->s = TRUE;
    }
}

t_flag*cmd_get_flag_obj(t_cmd_state *state, char flag)
{
    int i;

    i = 0;
    while (g_cmd_flags[i].flag) {
        if (g_cmd_flags[i].flag == flag) return (&g_cmd_flags[i]);

        i++;
    }
    if (state->cmd)
        ft_printf("%s: illegal option -- %c\n%s\n",
            state->cmd->cmd,
            flag,
            state->cmd->usage);
    ft_error(ERR_NO_MSG);
    return (NULL);
}
