/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:25:26 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 17:49:12 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "libft.h"

// TODO Find a way to make this automatically
// Replace all EXIT_SUCCESS by numbers

int flag_s_handler(t_cmd_state *state, int argc, char **argv, int argc_i){
	if (argc_i + 1 >= argc)
		return (EXIT_FAILURE);
	state->s_value = argv[argc_i + 1];

	return (EXIT_SUCCESS);
}


static void activate_flag(t_cmd_state *state, char *flag) {
	if (!ft_strcmp(flag, "p")) {
		state->p = TRUE;
	} else if (!ft_strcmp(flag, "q")) {
		state->q = TRUE;
	} else if (!ft_strcmp(flag, "r")) {
		state->r = TRUE;
	} else if (!ft_strcmp(flag, "s")) {
		state->s = TRUE;
	}
}

// TODO Set message for all errors
static int analyse_arg(t_cmd_state *state, int argc, char **argv, int argc_i) {
	int i;

	i = 0;
	while(!state->input_files && g_common_flags[i].flag) {
		if (!ft_strcmp(g_common_flags[i].flag, argv[argc_i])) {
			activate_flag(state, argv[argc_i]);

			if (g_common_flags[i].arg_count <= argc - argc_i ||
				(g_common_flags[i].handler && g_common_flags[i].handler(state, argc, argv, argc_i)))
				return (-1);

			return (g_common_flags[i].arg_count);
		} else {
			break;
		}
		i++;
	}
	if (!state->input_files)
		state->input_files = argv + argc_i;
	state->input_file_count++;

	return (0);
}

// TODO Do global error handling and in .go file test for all error cases
int set_cmd_state(t_cmd_state *state, int argc, char **argv) {
	int i;
	int ret;

	ft_bzero(state, sizeof(t_cmd_state));
	i = 2;
	while (i < argc) {
		ret = analyse_arg(state, argc, argv, i);
		// Si return -1 error
		if (ret)
			return (EXIT_FAILURE);
		i += 1 + ret;
	}
	return (EXIT_SUCCESS);
}
