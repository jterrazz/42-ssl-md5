/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:03:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/10 16:51:19 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_DISPATCHER_H
# define ARG_DISPATCHER_H

#include "./common/common.h"

// TODO Transform all projects file name to a verb

typedef struct		s_cmd_state {
	char				**input_files;
	int				input_file_count;
	bool				p;
	bool				q;
	bool				r;
	bool				s;
}					t_cmd_state;

typedef char * (*t_cmd_handler)(const char *msg, size_t msg_len);

typedef struct		s_cmd {
	const char			*cmd;
	t_cmd_handler		handler;
}					t_cmd;

typedef int (*t_flag_handler)(t_cmd_state *state, int argc, char **argv, int argc_i);

typedef struct		s_flag {
	const char			*flag;
	t_flag_handler		handler;
	int				arg_count;
}					t_flag;

int dispatch_cmd(int argc, char **argv);

int p_flag_handler(t_cmd_state *state, int argc, char **argv, int argc_i);
int q_flag_handler(t_cmd_state *state, int argc, char **argv, int argc_i);
int r_flag_handler(t_cmd_state *state, int argc, char **argv, int argc_i);
int s_flag_handler(t_cmd_state *state, int argc, char **argv, int argc_i);

extern const t_cmd g_cmds[];
extern const t_flag g_common_flags[];

#endif
