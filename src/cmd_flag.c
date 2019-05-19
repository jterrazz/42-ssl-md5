/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:34:20 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/17 19:03:28 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"

int cmd_flag_s_handler(t_cmd_state *state, int argc_i)
{
    if (argc_i + 1 >= state->argc) return (ft_error(ERR_S_FLAG_NO_ARG)); // Test with last arg is s // Add error name

    // TODO Secure malloc and realloc
    // TODO No realloc allowed
    state->s_argv =
        realloc(state->s_argv, state->s_argc * sizeof(char *));
    state->s_argv[state->s_argc]	= state->argv[argc_i + 1];
    state->s_argc			+= 1;

    return (SUCCESS);
}
// Add this
// 42-ssl-md5 git:(master) ✗ md5 -j
// md5: illegal option -- j
// usage: md5 [-pqrtx] [-s string] [files ...]

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
t_flag *cmd_get_flag_obj(char flag)
{
    int		i;

    i = 0;
    while (g_common_flags[i].flag) {
        if (g_common_flags[i].flag == flag) return (&g_common_flags[i]);
        i++;
    }
    return NULL;
}
