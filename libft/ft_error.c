/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:12:16 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:12:18 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	err_msg(const char *str)
{
	write(2, "Error message: ", 15);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	perror("Error Description: ");
	exit(EXIT_FAILURE);
}
