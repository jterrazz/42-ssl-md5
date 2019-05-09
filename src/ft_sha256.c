/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:15:16 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/09 16:14:13 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_sha256/sha256.h"
#include "ft_printf.h"

void ft_sha256(int argc, char **argv) {
	char *test = sha256("hi there", 8);
	ft_printf("SHA256: %s\n", test);
	ft_printf("SHA256: 0x9B96A1FE1D548CBBC960CC6A0286668FD74A763667B06366FB2324269FCABAA4\n");
}
