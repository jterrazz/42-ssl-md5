/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:06:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/15 13:34:12 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./cmd.h" // TODO Remove and delete .h if not used
#include "libft.h" // Del ?
#include <stdlib.h>

// Compare errors to https://github.com/psprawka/Ft_ssl/blob/master/srcs/get.c
// TODO Do error handling probably with 1 GLOBAL (Check if that's usefull probably not)
static int ft_ssl_error(int argc, char **argv)
{
	if (argc < 2) {
		ft_printf(
			"usage: ft_ssl command [command opts] [command args]\n");
		return (EXIT_SUCCESS);
	}

	ft_printf("ft_ssl: Error: '%s' is an invalid command\n\n", argv[1]);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n");
	return (EXIT_SUCCESS);
}

// TODO Adapt and add printf with libft
//
// static void show_result(t_cmd cmd, const char *input, const char *source, size_t length) {
//      char *hash;
//
//      hash = cmd.handler(input, length);
//      if (source) {
//              ft_printf("%s (%s) %s\n", cmd.full_name, source, hash);
//      } else {
//              ft_printf("%s\n", hash);
//      }
//      free(hash);
// }

static int launch_cmd(const t_cmd cmd, t_cmd_state *state)
{
	// Check if file or else listen for input ?
	// First msg from FD 1
	int     i;
	t_file *file;

	i = 0;
	// For each file + for each -s
	if (!state->s_argc && !state->input_file_count) {
		file = read_fd_content(0);
		ft_printf("%s", file->data);
		show_result(cmd, file->data, NULL, file->length);
		free_file(file);
		return (EXIT_SUCCESS);
	}

	// md5 -s -r -rs -r
	// TODO Do on 1 -
	// Consider multiple -s

	while (state->s_argc--) {
		show_result(cmd, state->s_argv[i], state->s_argv[i],
		            ft_strlen(state->s_argv[i])); // Add "" to source data
		i++;
	}
	i = 0;
	while (state->input_file_count--) { // Read from file
		file = get_file_content(state->input_files[i]);
		if (!file) {
			ft_printf("no file\n");
		} else {
			show_result(cmd, file->data, cmd.full_name,
			            file->length);
			free_file(file);
		}
		i++;
	}
	free(state->s_argv);
	return (EXIT_SUCCESS);
}

// TODO Transfert into after ft_error fix
static int dispatch_cmd(int argc, char **argv)
{
	int         i;
	t_cmd_state state;

	i = 0;
	if (argc < 2)
		return (EXIT_FAILURE);
	while (g_cmds[i].cmd) {
		if (!ft_strcmp(g_cmds[i].cmd, argv[1]))
			return (set_cmd_state(&state, argc, argv) || launch_cmd(
					g_cmds[i], &state));
		i++;
	}

	return (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	return (dispatch_cmd(argc, argv) && ft_ssl_error(argc, argv));
}
