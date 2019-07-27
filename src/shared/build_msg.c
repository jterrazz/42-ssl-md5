/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:51:55 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:48:25 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./shared.h"

unsigned char	*build_msg(const char *msg, size_t msg_len,
	size_t formatted_msg_len, bool is_little_endian)
{
	unsigned char	*formatted_msg;
	size_t			cursor;

	if (!(formatted_msg = malloc(formatted_msg_len)))
		return (NULL);
	ft_memcpy(formatted_msg, msg, msg_len);
	formatted_msg[msg_len] = 0b10000000;
	cursor = msg_len + 1;
	while (cursor < formatted_msg_len)
		formatted_msg[cursor++] = 0;
	*(uint64_t *)(formatted_msg + cursor - 8) =
		is_little_endian ? 8 * msg_len : ft_bswap_uint64(8 * msg_len);
	return (formatted_msg);
}
