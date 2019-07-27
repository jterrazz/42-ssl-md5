/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:42:52 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha384.h"

char	*ft_sha384(const char *msg, size_t msg_len)
{
	unsigned char	*formatted_msg;
	t_8_uint64		buffers;
	char			*hash;
	char			*cropped_hash;

	if (!(formatted_msg = build_msg(msg, msg_len,
		SHA512_CHUNK_COUNT(msg_len) * SHA512_CS, FALSE)))
		return (NULL);
	ft_uint64_arr_cpy(buffers, g_sha384_default_buffers, 8);
	sha512_run_ops(buffers, formatted_msg, msg_len);
	free(formatted_msg);
	if (!(hash = build_hash_64(buffers, 8, FALSE)))
		return (NULL);
	if (!(cropped_hash = ft_strnew(BYTE_TO_B(384) * 2)))
		return (NULL);
	ft_strncpy(cropped_hash, hash, BYTE_TO_B(384) * 2);
	free(hash);
	return (cropped_hash);
}
