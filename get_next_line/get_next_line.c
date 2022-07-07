/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:13 by jthor             #+#    #+#             */
/*   Updated: 2022/01/14 18:15:51 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Main get_next_line function. The procedure is as follows:                 *
 *                                                                           *
 * 1. Simple error checks.                                                   *
 * 2. String initialisation.                                                 *
 * 3. Fill buffer and offload to static variable until EOF or '\n'.          *
 * 4. Return                                                                 *
 *      a) NULL if nothing is read and static variable is empty.             *
 *      b) The next line in the file, processed by the function final_line.  *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char	*get_next_line(int fd)
{
	static char	*stat_str;
	char		*buff;
	ssize_t		read_ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (!stat_str)
		ft_handleptr(&stat_str, 0);
	while (read_buff(fd, &buff, &read_ret) > 0)
	{
		handle_buff(&stat_str, &buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	ft_handleptr(&buff, 1);
	if (read_ret <= 0 && !stat_str)
		return (NULL);
	return (final_line(&stat_str));
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Helper function created to read the text file, fill the buffer, and NULL  *
 * terminate it. The return value of the read() operation is used as a loop  *
 * control, as well as to indicate if the EOF is reached.                    *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

ssize_t	read_buff(int fd, char **buff, ssize_t *read_ret)
{
	ssize_t	ret;

	ret = read(fd, *buff, BUFFER_SIZE);
	if (ret > 0)
		(*buff)[ret] = '\0';
	*read_ret = ret;
	return (ret);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Helper function created to offload the filled buffer to the static        *
 * variable. The variable temp temporarily holds the new line after          *
 * concatenation while stat_str is freed in a proper manner.                 *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void	handle_buff(char **stat_str, char **buff)
{
	char	*temp;

	temp = ft_strjoin(*stat_str, *buff);
	ft_handleptr(stat_str, 1);
	*stat_str = temp;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Helper function created to process the final line that may or may not     *
 * include a '\n'. The basic idea is as follows                              *
 *                                                                           *
 * In the case of newline,                                                   *
 *                                                                           *
 * BEFORE                                                                    *
 * stat_str = "Hello\nWorld\0"                                               *
 *                                                                           *
 * AFTER                                                                     *
 * ret      = "Hello\n"                                                      *
 * stat_str = "World\0"                                                      *
 *                                                                           *
 * In the case of no newline,                                                *
 *                                                                           *
 * BEFORE                                                                    *
 * stat_str = "Hello World\0"                                                *
 *                                                                           *
 * AFTER                                                                     *
 * ret      = "Hello World\0"                                                *
 * stat_str = <freed>                                                        *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char	*final_line(char **stat_str)
{
	char	*ret;
	char	*leftov;
	int		i;

	i = 0;
	while ((*stat_str)[i] && (*stat_str)[i] != '\n')
		i++;
	if ((*stat_str)[i])
	{
		i += 1;
		ret = ft_strldup(*stat_str, i);
		leftov = ft_strldup(*stat_str + i, ft_strlen(*stat_str) - i);
		ft_handleptr(stat_str, 1);
		if (!leftov || !(leftov[0]))
			ft_handleptr(&leftov, 1);
		else
			*stat_str = leftov;
	}
	else
	{
		ret = ft_strldup(*stat_str, ft_strlen(*stat_str));
		ft_handleptr(stat_str, 1);
	}
	return (ret);
}
