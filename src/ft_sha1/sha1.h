/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:31:46 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA1_H
# define SHA1_H

# include "../shared/shared.h"
# include "../ft_sha256/sha256.h"

/*
** Globals
*/

extern const uint32_t	g_sha1_default_buffers[5];
extern const uint32_t	g_sha1_k_buffers[4];

/*
** Methods
*/

char		*ft_sha1(const char *msg, size_t msg_len);

uint32_t	ft_sha1_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t	ft_sha1_par(uint32_t x, uint32_t y, uint32_t z);
uint32_t	ft_sha1_ma(uint32_t x, uint32_t y, uint32_t z);

#endif
