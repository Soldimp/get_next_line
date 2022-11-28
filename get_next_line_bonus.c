/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:59:12 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/28 17:44:13 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (stash[fd][i])
			stash[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (stash[fd][0] || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, stash[fd]);
		if (stashfree(stash[fd]))
			break ;
	}
	return (line);
}

/*int main()
{
	int fd = 0;
	char *to_free;
	fd = open("./fd.txt", O_RDWR);
	printf("%d\n", fd);
	to_free = get_next_line(fd);
	printf("%s", to_free);
	close(fd);
}*/