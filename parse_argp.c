/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:51:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/27 16:50:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct		s_argp
{
	char			sign;
	unsigned		active : 1;
	char			*description;
}					t_argp;

t_argp		g_argp[] =
{
	{'1', 0, "List one file per line"},
	{'l', 0, "List in long format"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'r', 0, "Reverse the order of the sort"},
	{'t', 0, "Sort by time modified (most recently modified first)"},
	{'-', 0, "End of options"},
	{0, 0, NULL}
};

void		parse_argp(int ac, char *av[])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			j = 1;
			while (av[i][j] != '\0')
			{
				k = 0;
				while (g_argp[k].sign != 0)
				{
					if (g_argp[k].sign == av[i][j])
						g_argp[k].active = 1;
					++k;
				}
				j++;
			}
		}
		i++;
	}
}

int			main(int ac, char *av[])
{
	(void)ac; (void)av;
	int i;

	i = 0;
	parse_argp(ac - 1, av + 1);
	while (g_argp[i].sign != 0)
	{
		printf("%d ", g_argp[i].active);
		printf("%c\n", g_argp[i].sign);
		++i;
	}
	return (0);
}
