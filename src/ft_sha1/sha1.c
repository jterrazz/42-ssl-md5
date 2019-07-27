/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:09 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:33:39 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sha1.h"

static void		init_w_array(t_80_uint32 w_array, unsigned char *formatted_msg)
{
	int i;

	i = 0;
	while (i < 80)
	{
		if (i < 16)
			w_array[i] = ft_bswap_uint32(((uint32_t *)formatted_msg)[i]);
		else
			w_array[i] = ft_brotate_left(w_array[i - 3]
				^ w_array[i - 8] ^ w_array[i - 14] ^ w_array[i - 16], 1);
		i++;
	}
}

static void		sha1_shuffle_buffers(t_8_uint32 buffers,
	t_80_uint32 w_array)
{
	int			i;
	uint32_t	temp;

	i = 0;
	while (i < 80)
	{
		temp = ft_brotate_left(buffers[0], 5);
		if (i < 20)
			temp += ft_sha1_ch(buffers[1], buffers[2], buffers[3]);
		else if (i < 40)
			temp += ft_sha1_par(buffers[1], buffers[2], buffers[3]);
		else if (i < 60)
			temp += ft_sha1_ma(buffers[1], buffers[2], buffers[3]);
		else
			temp += ft_sha1_par(buffers[1], buffers[2], buffers[3]);
		temp += g_sha1_k_buffers[i / 20];
		temp += buffers[4] + w_array[i];
		buffers[4] = buffers[3];
		buffers[3] = buffers[2];
		buffers[2] = ft_brotate_left(buffers[1], 30);
		buffers[1] = buffers[0];
		buffers[0] = temp;
		i++;
	}
}

static void		sha1_run_ops(t_8_uint32 buffers,
	unsigned char *formatted_msg, size_t msg_len)
{
	size_t			chunk_i;
	t_80_uint32		w_array;
	t_8_uint32		internal_buffers;

	chunk_i = 0;
	while (chunk_i < SHA256_CHUNK_COUNT(msg_len))
	{
		init_w_array(w_array, formatted_msg + chunk_i * SHA256_CHUNK_SIZE);
		ft_uint32_arr_cpy(internal_buffers, buffers, 5);
		sha1_shuffle_buffers(internal_buffers, w_array);
		ft_uint32_arr_assign_add(buffers, internal_buffers, 5);
		chunk_i++;
	}
}

char			*ft_sha1(const char *msg, size_t msg_len)
{
	unsigned char	*formatted_msg;
	t_8_uint32		buffers;
	char			*hash;

	if (!(formatted_msg = build_msg(msg, msg_len, SHA256_CHUNK_COUNT(msg_len)
		* SHA256_CHUNK_SIZE, FALSE)))
		return (NULL);
	ft_uint32_arr_cpy(buffers, g_sha1_default_buffers, 5);
	sha1_run_ops(buffers, formatted_msg, msg_len);
	free(formatted_msg);
	if (!(hash = build_hash(buffers, 5, FALSE)))
		return (NULL);
	return (hash);
}
