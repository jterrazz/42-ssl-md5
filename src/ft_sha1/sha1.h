/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:07 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/26 00:28:55 by jterrazz         ###   ########.fr       */
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
extern const uint32_t g_sha1_k_buffers[4];

/*
** Prototypes
*/

char *ft_sha1(const char *msg, size_t msg_len);

#endif
