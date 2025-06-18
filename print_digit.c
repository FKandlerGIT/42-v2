/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:38:54 by codespace         #+#    #+#             */
/*   Updated: 2025/06/18 21:26:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int print_digit(int n)
{
    int len;
    int m;
    
    m = n;
    len = 0;
    if(n == 0)
        return (1);
    if (n < 0)
    {
        len++;
        n = -n;
    }
    while(n != 0)
    {
        len++;
        n = n / 10;
    }
    ft_putnbr_fd(m, 1);
    return(len);   
}
