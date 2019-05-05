/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:11:58 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/05 13:18:27 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

char	*ft_uitoa_base(uintmax_t nb, intmax_t base, char letter);
unsigned int ft_rotate_bits_left(unsigned int x, char rotations);
char	*ft_uitoa_base_len(uintmax_t nb, intmax_t base, char letter, size_t len);

#endif
