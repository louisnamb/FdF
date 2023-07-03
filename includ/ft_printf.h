/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:54:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/04/11 15:22:33 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t			ft_strlen(const char *s);

int				ft_putstr_fd(char *s, int fd);

int				ft_putchar_fd(char c, int fd);

int				ft_putnbr_fd(int n, int fd, int total, int *sum);

int				whichspecifier(const char c, va_list var);

int				ft_printf(const char *format, ...);

unsigned int	ft_uputnbr_fd(unsigned int n, int fd, int total, int *sum);

int				ft_hputstr(char *s, int fd, int length, int ptr);

int				ft_hexlen(unsigned long long int num, int base);

char			*ptrmkr(char *ptr, unsigned long long num);

int				ft_convert(unsigned long long num, int base, int low, int ptr);

int				ft_printf(const char *format, ...);

#endif
