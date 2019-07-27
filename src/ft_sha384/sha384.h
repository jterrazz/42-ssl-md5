/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:25:41 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:42:29 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA384_H
# define SHA384_H

# include "../shared/shared.h"
# include "../ft_sha512/sha512.h"

/*
** Globals
*/

extern const uint64_t	g_sha384_default_buffers[8];

/*
** Prototypes
*/

char *ft_sha384(const char *msg, size_t msg_len);

#endif
