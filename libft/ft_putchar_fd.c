/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:35:07 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/16 13:55:18 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//fd is the file descriptor where the character will be written.
//This could be 1 for standard output, 2 for standard error,
// or any file descriptor returned by the open function.

// 0 - stdin (Standard Input): Represents the standard input,
// usually from the keyboard.
// 1 - stdout (Standard Output): Represents the standard output,
//where the program writes its output data.
// 2 - stderr (Standard Error): Represents the standard error,
//where the program writes its error messages.

//In a Unix-like operating system, file descriptors
//(often abbreviated as "FD") are non-negative integer values
//that provide a low-level mechanism for processes
//to reference and interact with files, sockets, and other I/O operations.