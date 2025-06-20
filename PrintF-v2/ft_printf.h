/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:24:46 by fekandle          #+#    #+#             */
/*   Updated: 2025/06/20 18:04:58 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_format(char sign, va_list ap);
int	unsign(unsigned long n, unsigned long base, const char *symbols, int fd);
int	print_str(char *c);
int	print_ptr(void *p);
int	print_percent(void);
int	print_digit(int n);

#endif
