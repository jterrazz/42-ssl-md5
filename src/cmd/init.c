/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:25:26 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/25 20:51:41 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"

static int cmd_arg_is_flag(t_cmd_state *state, int argc_i)
{
	t_flag	*flag_obj;
	int		args_to_skip;
	int		handler_ret;
	int		i;

	i = 1;
	args_to_skip = 0;
	while (state->argv[argc_i][i])
    {
		if (!(flag_obj = cmd_get_flag_obj(state, state->argv[argc_i][i])))
			return (FAILURE);
		if (flag_obj->handler)
		{
			if ((handler_ret = flag_obj->handler(state, argc_i)) < 0)
				return (handler_ret);
		}
		if (flag_obj->arg_count > args_to_skip)
			args_to_skip = flag_obj->arg_count;
		cmd_activate_flag(state, state->argv[argc_i][i]);
		i++;
	}
	return (args_to_skip);
}

static int cmd_analyse_arg(t_cmd_state *state, int argc_i)
{
	if (!state->input_file_count && (state->argv[argc_i][0] == '-') &&
		state->argv[argc_i][1])
		return (cmd_arg_is_flag(state, argc_i));
	else if (!state->input_file_count)
		state->input_files = state->argv + argc_i;
	state->input_file_count++;
	return (SUCCESS);
}

int cmd_init_state(t_cmd_state *state, int argc, char **argv, t_cmd *cmd)
{
	int ret;
	int argc_i;

	argc_i = 2;
	ft_bzero(state, sizeof(t_cmd_state));
	state->argc = argc;
	state->argv = argv;
	state->cmd = cmd;
	while (argc_i < argc)
	{
		if ((ret = cmd_analyse_arg(state, argc_i)) < 0)
			return (FAILURE);
		argc_i += 1 + ret;
	}
	return (SUCCESS);
}
