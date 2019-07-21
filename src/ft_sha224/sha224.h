/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/21 21:25:00 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
#define SHA224_H

#include "../shared/shared.h"
#include "../ft_sha256/sha256.h"

/*
** Globals
*/

extern const uint32_t	g_sha224_default_buffers[8];

/*
** Prototypes
*/

char *ft_sha224(const char *msg, size_t msg_len);

#endif
