/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shells.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <atoutain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 14:36:54 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 19:03:38 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int				get_next_line(int const fd, char **line);

typedef void	(*sighandler_t)(int);
char c = '\0';

void	handle_signal(int signo)
{
	printf("\nPEDISHELL (╯°□°）╯︵ ");
	fflush(stdout);
}

int		main(int argc, char **argv, char **envp)
{
	char	**line;

	line = malloc(sizeof(char *) * 4);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	printf("\nPEDISHELL (╯°□°）╯︵ ");
	while (c != EOF)
	{
		get_next_line(0, line);
		c = getchar();
		if (c == '\n')
			printf("PEDISHELL (╯°□°）╯︵ ");
	}
	printf("\n");
	return (0);
}
