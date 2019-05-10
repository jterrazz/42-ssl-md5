/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 18:11:19 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./cmd.h" // TODO Remove and delete .h if not used
#include "libft.h" // Del ?
#include "./common/common.h"

// TODO Do error handling probably with 1 GLOBAL (Check if that's usefull probably not)
static int ft_ssl_error(int argc, char **argv) {
	if (argc < 2) {
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (EXIT_SUCCESS);
	}

	ft_printf("ft_ssl: Error: '%s' is an invalid command\n\n", argv[1]);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n");
	return (EXIT_SUCCESS);
}

// TODO Adapt and add printf with libft

static int run_cmd(t_cmd cmd, t_cmd_state *state) {
	// Check if file or else listen for input ?
	// First msg from FD 1
	char *hash;
	int i;

	i = 0;
	// For each file + for each -s
	while (state->input_file_count--) {
		hash = cmd.handler(state->input_files[i], ft_strlen(state->input_files[i]));
		ft_printf("%s (%s) = %s\n", cmd.full_name, state->input_files[i], hash);
		i++;
	}
	return (EXIT_SUCCESS);
}

// TODO Transfert into after ft_error fix
static int dispatch_cmd(int argc, char **argv) {
	int i;
	t_cmd_state state;

	i = 0;
	if (argc < 2)
		return (EXIT_FAILURE);
	while (g_cmds[i].cmd) {
		if (!ft_strcmp(g_cmds[i].cmd, argv[1]))
			return set_cmd_state(&state, argc, argv) || run_cmd(g_cmds[i], &state);
		i++;
	}

	return (EXIT_FAILURE);
}

int main(int argc, char **argv) {
	return dispatch_cmd(argc, argv) && ft_ssl_error(argc, argv);
}
