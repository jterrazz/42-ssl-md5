/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:20:48 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/15 13:57:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"
#include <unistd.h>
#include "fcntl.h"
#include "libft.h" // Del ?

void free_file(t_file *file)
{
	free(file->data);
	free(file);
}

t_file *read_fd_content(int fd)
{
	char	* str_tmp;
	char	buffer[CMD_BUFF_SIZE];
	t_file	*file;
	size_t	len;

	if (!(file = malloc(sizeof(t_file))))
		return (NULL); // Make errors names
	ft_bzero(file, sizeof(t_file));
	while ((len = read(fd, buffer, CMD_BUFF_SIZE)) > 0) {
		if (!(str_tmp = malloc(file->length + len)))
			return (NULL); // Secure
		if (file->length)
			ft_memmove(str_tmp, file->data, file->length);
		ft_memmove(str_tmp + file->length, buffer, len);
		free(file->data);
		file->data = str_tmp;
		file->length += len;
	}
	return (file);
}

t_file *get_file_content(char *filename)
{
	int	fd;
	t_file	*file;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL); // show error
	file = read_fd_content(fd);

	close(fd); // Secure ???
	return (file);
	// Need to return the length
	// Need to return the malloced zone
	// Dont forget to free it after
}
