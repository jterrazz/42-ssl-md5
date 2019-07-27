/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:03:38 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/26 00:35:43 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_DISPATCHER_H
#define ARG_DISPATCHER_H

#define CMD_BUFF_SIZE 1000

#include "../shared/shared.h"
#include "../ft_md5/md5.h"
#include "../ft_sha256/sha256.h"
#include "../ft_sha512/sha512.h"
#include "../ft_sha384/sha384.h"
#include "../ft_sha224/sha224.h"
#include "../ft_sha1/sha1.h"

typedef struct      s_file {
    char	*data;
    size_t	length;
}      t_file;


typedef struct      s_cmd_state {
    char	**input_files;
    int		input_file_count;
    t_bool	p;
    t_bool	q;
    t_bool	r;
    t_bool	s;
    struct s_cmd   *cmd;
    int		argc;
    char	**argv;
    int		s_argc;
    char	**s_argv;
}           t_cmd_state;

typedef int (*t_flag_handler)(t_cmd_state *state, int argc_i);
typedef char * (*t_cmd_handler)(const char *msg, size_t msg_len);

typedef struct      s_cmd {
    const char		*cmd;
    const char		*full_name;
    t_cmd_handler	handler;
    const char      *usage;
}                   t_cmd;

typedef struct      s_flag {
    const char		flag;
    t_flag_handler	handler;
    int			arg_count;
}                   t_flag;

/*
** Globals
*/

extern t_cmd	g_cmds[];
extern t_flag	g_cmd_flags[];

/*
** Prototypes
*/

void	cmd_activate_flag(t_cmd_state *state, char flag);
t_flag	*cmd_get_flag_obj(t_cmd_state *state, char flag);
int	cmd_flag_s_handler(t_cmd_state *state, int argc_i);
int	cmd_clean(t_cmd_state *state);

int	cmd_run(const t_cmd cmd, t_cmd_state *state);
int	cmd_init_state(t_cmd_state *state, int argc, char             **argv, t_cmd *cmd);
t_file	*get_file_content(char *filename);
t_file	*read_fd_content(int fd);
void	free_file(t_file *file);

#endif
