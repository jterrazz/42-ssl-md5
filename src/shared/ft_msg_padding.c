/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:51:55 by jterrazz          #+#    #+#             */
/*   Updated: 2019/06/03 23:19:46 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared/shared.h"
#include "libft.h"

unsigned char*ft_ssl_msg_padding(const char *msg, size_t input_len,
    size_t output_len, bool is_little_endian)
{
    unsigned char	*msg_buffer;
    size_t		    cursor;

    if (!(msg_buffer = malloc(output_len)))
        return (NULL);

    ft_memcpy(msg_buffer, msg, input_len);
    msg_buffer[input_len] = 0b10000000;
    cursor		= input_len + 1;

    while (cursor < output_len)
        msg_buffer[cursor++] = 0;

    *(uint64_t *)(msg_buffer + cursor - 8) =
        is_little_endian ? 8 * input_len : ft_bswap_uint64(8 * input_len);

    return (msg_buffer);
}
