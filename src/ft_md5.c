/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:12:56 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/07 18:51:26 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_md5/md5.h"
#include "ft_printf.h"

// TODO Install atom in command line
// TODO Learn go and use it in tests
// TODO Clean atom packages
// TODO Adapt libs to use in projects
// TODO At the end, use latest version of my libs github
// TODO Explain in README.md the process with our algo
// Rename to manager

void ft_md5(int argc, char **argv) {
	char *test = md5("s", 1);
	ft_printf("MD5: %s\n", test);
}
