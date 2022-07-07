/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:25 by jthor             #+#    #+#             */
/*   Updated: 2022/01/13 16:57:27 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);

ssize_t	read_buff(int fd, char **buff, ssize_t *read_ret);
void	handle_buff(char **stat_str, char **buff);
char	*final_line(char **stat_str);

char	*ft_strldup(char const *s, int len);
void	ft_handleptr(char **ptr, int mode);

#endif
