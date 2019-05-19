/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:03:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/17 19:00:52 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_DISPATCHER_H
#define ARG_DISPATCHER_H

#define CMD_BUFF_SIZE 1000

#include "./common/common.h"
#include "./error.h"

typedef struct      s_file {
    char	*data;
    size_t	length;
}                   t_file;

typedef struct      s_cmd_state {
    char	**input_files;
    int		input_file_count;
    bool	wrong_flag;
    bool	p;
    bool	q;
    bool	r;
    bool	s;
    int     argc;
    char    **argv;
    int		s_argc;
    char	**s_argv;
}           t_cmd_state;

typedef char * (*t_cmd_handler)(const char	*msg,
    size_t					msg_len);

typedef int (*t_flag_handler)(t_cmd_state	*state,
    int						argc_i);

typedef struct      s_cmd {
    const char		*cmd;
    const char		*full_name;
    t_cmd_handler	handler;
}           t_cmd;

typedef struct      s_flag {
    const char		flag;
    t_flag_handler	handler;        // TODO Maybe remove
    int			arg_count;
}           t_flag;

void cmd_activate_flag(t_cmd_state *state, char flag);
t_flag *cmd_get_flag_obj(char flag);
int cmd_flag_s_handler(t_cmd_state	*state,
    int				argc_i);
int cmd_clean(t_cmd_state *state);

int	cmd_run(const t_cmd cmd, t_cmd_state *state);
int	cmd_set_state(t_cmd_state	*state,
    int					argc,
    char				**argv);
t_file	* get_file_content(char *filename);
t_file	* read_fd_content(int fd);
void	free_file(t_file *file);

extern const t_cmd	g_cmds[];
extern t_flag	g_common_flags[];

#endif  /* ifndef ARG_DISPATCHER_H */
