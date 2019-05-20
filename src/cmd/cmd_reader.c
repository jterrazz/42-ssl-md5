/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:20:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/20 18:36:18 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include "fcntl.h"
#include "libft.h"
#include <unistd.h>

void free_file(t_file *file)
{
    if (file)
        free(file->data);
    free(file);
}

t_file*read_fd_content(int fd)
{
    char	*str_tmp;
    char	buffer[CMD_BUFF_SIZE];
    t_file	*file;
    int		len;

    if (!(file = malloc(sizeof(t_file)))) {
        ft_error(ERR_ERRNO);
        return (NULL);
    }
    ft_bzero(file, sizeof(t_file));
    while ((len = read(fd, buffer, CMD_BUFF_SIZE)) > 0) {
        if (!(str_tmp = malloc(file->length + len))) {
            ft_error(ERR_ERRNO);
            return (NULL);
        }
        if (file->length)
            ft_memmove(str_tmp, file->data, file->length);
        ft_memmove(str_tmp + file->length, buffer, len);
        free(file->data);
        file->data	= str_tmp;
        file->length	+= len;
    }
    if (len < 0) {
        ft_error(ERR_ERRNO);
        return (NULL);
    }
    return (file);
}

t_file*get_file_content(char *filename)
{
    int		fd;
    t_file	*file;

    if ((fd = open(filename, O_RDONLY)) < 0) {
        ft_error(ERR_ERRNO);
        return (NULL);
    }
    if (!(file = read_fd_content(fd)))
        return (NULL);

    if (close(fd) < 0) {
        ft_error(ERR_ERRNO);
        return (NULL);
    }
    return (file);
}
