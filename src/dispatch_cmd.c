/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:00:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 17:01:02 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dispatch.h" // TODO Remove and delete .h if not used
#include "libft.h" // Del ?
#include "./common/common.h"

// TODO Adapt and add printf with libft

int p_flag_handler(t_cmd_state *state, int argc, char **argv, int argc_i) {

}

static int set_flags_state(t_cmd_state *state, int argc, char **argv, int argc_i) {
	int i;

	i = 0;
	while(g_common_flags[i].flag) {
		if (!ft_strcmp(g_common_flags[i].flag, argv[argc_i])) {
			if (g_common_flags[i].arg_count <= argc - argc_i && g_common_flags[i].handler) {
				if (g_common_flags[i].handler(state, argc, argv, argc_i))
					return (-1);
				return (g_common_flags[i].arg_count);
			}
		}
		i++;
	}
	// return the nb to increase
	return (0);
}

// TODO Do global error handling and in .go file test for all error cases
static int set_cmd_state(t_cmd_state *state, int argc, char **argv) {
	int i;
	int ret;

	ft_bzero(state, sizeof(t_cmd_state));
	i = 2;
	while (i < argc) {
		ret = set_flags_state(state, argc, argv, i);
		// Si return -1 error
		if (ret)
			return (EXIT_FAILURE);
		i += 1 + ret;
	}
	return (EXIT_SUCCESS);
}

static int run_cmd_handler(t_cmd_handler handler, t_cmd_state *state) {
	// Check if file or else listen for input ?
	return (EXIT_SUCCESS);
}

int dispatch_cmd(int argc, char **argv) {
	int i;
	t_cmd_state state;

	i = 0;
	if (argc < 2)
		return (EXIT_FAILURE);
	while (g_cmds[i].cmd) {
		if (!ft_strcmp(g_cmds[i].cmd, argv[1]))
			return set_cmd_state(&state, argc, argv) || run_cmd_handler(g_cmds[i].handler, &state);
		i++;
	}

	return (EXIT_FAILURE);
}
