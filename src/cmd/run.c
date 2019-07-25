/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:59:39 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/25 23:50:34 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"

int print_ssl_pipe(const t_cmd cmd, const t_cmd_state *state)
{
    t_file	*file;
    char	*hash;
    char	*data;

    if ((!state->s_argc && !state->input_file_count) || (state->p))
    {
        if (!(file = read_fd_content(0)) || !(hash = cmd.handler(file->data, file->length)))
            return (FAILURE);
        if (!(data = ft_strnew(file->length)))
            return (ft_error(ERR_ERRNO));
        ft_memcpy(data, file->data, file->length);
        if (state->p)
            ft_printf("%s%s\n", data, hash);
        else
            ft_printf("%s\n", hash);
        free(data);
        free_file(file);
        free(hash);
    }
    return (SUCCESS);
}

static int print_ssl_strings(const t_cmd cmd, const t_cmd_state *state)
{
    int		i;
    char	*hash;

    i = 0;

    while (i < state->s_argc) {
        if (!(hash = cmd.handler(state->s_argv[i], ft_strlen(state->s_argv[i]))))
            return (FAILURE);
        if (state->q)
            ft_printf("%s\n", hash);
        else if (state->r)
            ft_printf("%s \"%s\"\n", hash, state->s_argv[i]);
        else
            ft_printf("%s (\"%s\") = %s\n", cmd.full_name, state->s_argv[i], hash);
        free(hash);
        i++;
    }
    return (SUCCESS);
}

static int print_file_result(const t_cmd cmd,
    const t_cmd_state *state, t_file *file, int i)
{
    char *hash;

    if (!(hash = cmd.handler(file->data, file->length)))
        return (FAILURE);
    if (state->q)
        ft_printf("%s\n", hash);
    else if (state->r)
        ft_printf("%s %s\n", hash, state->input_files[i]);
    else
        ft_printf("%s (%s) = %s\n", cmd.full_name, state->input_files[i], hash);
    free(hash);
    free_file(file);
    return (SUCCESS);
}

static int print_ssl_files(const t_cmd cmd, const t_cmd_state *state)
{
    int		i;
    t_file	*file;

    i = 0;
    while (i < state->input_file_count) {
        if (!(file = get_file_content(state->input_files[i])))
            ft_printf("ft_ssl: %s: %s: %s\n", cmd.cmd, state->input_files[i], strerror(errno));
        else if ((print_file_result(cmd, state, file, i) == FAILURE))
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}

int cmd_run(const t_cmd cmd, t_cmd_state *state)
{
    return (print_ssl_pipe(cmd, state) ||
            print_ssl_strings(cmd, state) ||
            print_ssl_files(cmd, state));
}
