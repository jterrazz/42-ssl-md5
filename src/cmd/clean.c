/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:56:23 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/27 12:14:20 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cmd.h"

int	cmd_clean(t_cmd_state *state)
{
	if (state)
		free(state->s_argv);
	return (SUCCESS);
}
