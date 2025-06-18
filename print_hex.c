/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:32:45 by codespace         #+#    #+#             */
/*   Updated: 2025/06/18 21:44:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int print_hex(unsigned int n, const char *symbols)
{
    int len;
    int m;
    
    m = n;
    len = 0;
    if(n == 0)
        return (1);
    while(n != 0)
    {
        len++;
        n = n / 16;
    }
    ft_putnbr_fd(m, 1);
    return(len);  
}