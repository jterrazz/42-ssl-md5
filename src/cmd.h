/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:03:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/13 17:32:59 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_DISPATCHER_H
# define ARG_DISPATCHER_H

#define CMD_BUFF_SIZE 1000

#include "./common/common.h"

// TODO Transform all projects file name to a verb

typedef struct		s_file {
	char				*data;
	size_t				length;
}					t_file;

typedef struct		s_cmd_state {
	char				**input_files;
	int					input_file_count;
	bool				p;
	bool				q;
	bool				r;
	bool				s;
	char				**s_argv;
	int					s_argc;
}					t_cmd_state;

typedef char * (*t_cmd_handler)(const char *msg, size_t msg_len);

typedef struct		s_cmd {
	const char			*cmd;
	const char			*full_name;
	t_cmd_handler		handler;
}					t_cmd;

typedef int (*t_flag_handler)(t_cmd_state *state, int argc, char **argv, int argc_i);

typedef struct		s_flag {
	const char			*flag;
	t_flag_handler		handler; // TODO Maybe remove
	int				arg_count;
}					t_flag;

int flag_s_handler(t_cmd_state *state, int argc, char **argv, int argc_i);

int set_cmd_state(t_cmd_state *state, int argc, char **argv);
t_file *get_file_content(char *filename);
t_file *read_fd_content(int fd);
void free_file(t_file *file);

extern const t_cmd g_cmds[];
extern const t_flag g_common_flags[];

#endif
