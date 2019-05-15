/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:59:39 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/15 17:35:35 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// TODO Secure the return of hash (if null) ?????

#include "./cmd.h" // TODO Remove and delete .h if not used
#include "ft_printf.h"
#include "libft.h" // Del ?

static int print_ssl_pipe(const t_cmd cmd, const t_cmd_state *state)
{
  t_file *file;
  char   *hash;

  if ((!state->s_argc && !state->input_file_count) || (state->p)) {
    file = read_fd_content(0);

    if (!(hash = cmd.handler(file->data, file->length))) return FAILURE;

    if (state->p)
      ft_printf("%s%s\n",
                file->data,
                hash);
    else ft_printf("%s\n",
                   hash);

    free_file(file);
    free(hash);
  }
  return EXIT_SUCCESS;
}

static int print_ssl_strings(const t_cmd cmd, const t_cmd_state *state)
{
  int   i;
  char *hash;

  i = 0;

  while (i < state->s_argc) {
    if (!(hash =
            cmd.handler(state->s_argv[i], ft_strlen(
                          state->s_argv[i])))) return FAILURE;

    if (state->q) ft_printf("%s\n", hash);
    else if (state->r) ft_printf("%s \"%s\"\n", hash, state->s_argv[i]);
    else ft_printf("%s (\"%s\") %s\n", cmd.full_name, state->s_argv[i], hash);
    free(hash);
    i++;
  }
  return EXIT_SUCCESS;
}

static int print_ssl_files(const t_cmd cmd, const t_cmd_state *state)
{
  int     i;
  char   *hash;
  t_file *file;

  i = 0;

  while (i < state->input_file_count) {
    file = get_file_content(state->input_files[i]);

    if (!file) {
      // ft_ssl: md5: -s: No such file or directory
      ft_printf("ft_ssl: %s: %s: No such file or directory\n",
                cmd.cmd,
                state->input_files[i]);
    } else {
      if (!(hash =
              cmd.handler(file->data, file->length))) return FAILURE;

      if (state->q) ft_printf("%s\n", hash);
      else if (state->r) ft_printf("%s %s\n", hash, state->input_files[i]);
      else ft_printf("%s (%s) %s\n", cmd.full_name, state->input_files[i], hash);
      free(hash);
      free_file(file);{

      }

    }
    i++;
  }
  return EXIT_SUCCESS;
}

int cmd_run(const t_cmd cmd, t_cmd_state *state)
{
  print_ssl_pipe(cmd, state);
  print_ssl_strings(cmd, state);
  print_ssl_files(cmd, state);
  free(state->s_argv);
  return EXIT_SUCCESS;
}
