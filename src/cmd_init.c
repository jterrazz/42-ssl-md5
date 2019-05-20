/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:25:26 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:36:48 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "libft.h"
#include <stdlib.h>

static int cmd_arg_is_flag(t_cmd_state *state, int argc_i)
{
    int i;
    int args_to_skip;
    int handler_ret;

    i			= 1;
    args_to_skip	= 0;

    while (state->argv[argc_i][i]) {
        t_flag *flag_obj;

        if (!(flag_obj = cmd_get_flag_obj(state->argv[argc_i][i])))
            return (FAILURE);

        if (flag_obj->handler) {
            if ((handler_ret = flag_obj->handler(state, argc_i)) < 0)
                return (handler_ret);
        }
        if (flag_obj->arg_count > args_to_skip)
            args_to_skip = flag_obj->arg_count;
        cmd_activate_flag(state, state->argv[argc_i][0]);
        i++;
    }
    return (args_to_skip);
}

static int cmd_analyse_arg(t_cmd_state *state, int argc_i)
{
    if (!state->input_file_count && (state->argv[argc_i][0] == '-') &&
        state->argv[argc_i][1]) {
        return (cmd_arg_is_flag(state, argc_i));
    } else if (!state->input_file_count) {
        state->input_files = state->argv + argc_i;
    }
    state->input_file_count++;

    return (SUCCESS);
}

int cmd_init_state(t_cmd_state *state, int argc, char **argv)
{
    int ret;
    int argc_i;

    argc_i = 2;
    ft_bzero(state, sizeof(t_cmd_state));
    state->argc = argc;
    state->argv = argv;

    while (argc_i < argc) {
        if ((ret = cmd_analyse_arg(state, argc_i)) < 0)
            return (FAILURE);

        argc_i += 1 + ret;
    }
    return (SUCCESS);
}