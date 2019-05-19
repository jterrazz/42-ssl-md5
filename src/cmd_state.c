/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:25:26 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/17 18:56:02 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "libft.h"
#include <stdlib.h>
// TODO Learn taquin
// Ternaire en python
// Learn better python for one project
// Learn C namespace
// Learn C BFS ?? (algo de tri)

/*
** Return the number of args to skip
** -1 for error
*/
//  Handle a wrong flag return
// Check it compares the return and not rhe -= result in => if (( d -= dd) > x)

static int cmd_arg_is_flag(t_cmd_state *state, int argc_i)
{
    int i;
    int ret;

    i	= 1;
    ret = 0;
    while (state->argv[argc_i][i]) {
        t_flag *flag_obj;

        flag_obj = cmd_get_flag_obj(state->argv[argc_i][i]);
        if (flag_obj->handler)
            ret += flag_obj->handler(state, argc_i);
        if (ret < 0 || ret > 1) // Error if > 1 = Request to read two times the next argument
            return ret;
        cmd_activate_flag(state, state->argv[argc_i][0]);
        i++;
    }
    return (ret);
}
// TODO Set message for all errors
/*
** Return the number of args to skip
** -1 for error
*/
static int cmd_analyse_arg(t_cmd_state *state, int argc_i)
{
    if (!state->input_files && (state->argv[argc_i][0] == '-')) {
        return (cmd_arg_is_flag(state, argc_i));
    }

    if (!state->input_file_count && state->argv[argc_i] && (*(state->argv[argc_i]) == '-')) {
        state->wrong_flag = TRUE;
    } else if (!state->input_file_count) {
        state->input_files = state->argv + argc_i;
        state->input_file_count++;
    } else {
        state->input_file_count++;
    }

    return (0);
}
int cmd_set_state(t_cmd_state *state, int argc, char **argv)
{
    int i;
    int ret;

    i = 2;
    ft_bzero(state, sizeof(t_cmd_state));
    state->argc = argc;
    state->argv = argv;

    while (i < argc) {
        ret = cmd_analyse_arg(state, i);

        if (ret == -1) return (FAILURE);

        i += 1 + ret;
    }
    return (SUCCESS);
}
