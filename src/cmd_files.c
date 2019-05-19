/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:20:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/19 20:36:17 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include <unistd.h>
#include "fcntl.h"
#include "libft.h" // Del ?

void free_file(t_file *file)
{
	if (file)
		free(file->data);
	free(file);
}

t_file *read_fd_content(int fd)
{
	char	*str_tmp;
	char	buffer[CMD_BUFF_SIZE];
	t_file	*file;
	size_t	len;

	if (!(file = malloc(sizeof(t_file)))) {
		ft_error(ERR_MALLOC_FAIL);
		return (NULL); // Make errors names
	}
	ft_bzero(file, sizeof(t_file));
	while ((len = read(fd, buffer, CMD_BUFF_SIZE)) > 0) { // Read return -1 secure
		if (!(str_tmp = malloc(file->length + len))) { // Secure
			ft_error(ERR_MALLOC_FAIL);
			return (NULL);
		}
		if (file->length)
			ft_memmove(str_tmp, file->data, file->length);
		ft_memmove(str_tmp + file->length, buffer, len);
		free(file->data);
		file->data = str_tmp;
		file->length += len;
	}
	return (file);
}
// Use all errors
t_file *get_file_content(char *filename)
{
	int	fd;
	t_file	*file;

	if ((fd = open(filename, O_RDONLY)) < 0) {
		ft_error(ERR_OPEN_FAIL);
		return (NULL); // show error
	} // Open a folder should print a message (shoudl continue )
	file = read_fd_content(fd);

	if (close(fd) < 0) {
		ft_error(ERR_CLOSE_FAIL);
		return (NULL);
	} // Secure ???
	return (file);
}
