/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:07:29 by yyyyyy            #+#    #+#             */
/*   Updated: 2024/11/21 12:21:37by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

char	*ft_optarg = NULL;
int		ft_optind = 1;
int		ft_optopt = '?';
t_bool	ft_opterr = TRUE;

static
t_bool	is_option(str arg)
{
	return arg[0] == '-' && ft_strcmp(arg, "-") && ft_strcmp(arg, "--");
}

static
void	swap_args(char *const argv[], int i, int j)
{
	char	*tmp;

	tmp = argv[i];
	((char **) argv)[i] = argv[j];
	((char **) argv)[j] = tmp;
}

static
void	move_to_front(char *const argv[], int i)
{
	while (i > 1 && !is_option(argv[i - 1]))
	{
		swap_args(argv, i, i - 1);
		i--;
	}
}

int		ft_getopt_long(
	int argc,
	char *const argv[],
	const char *optstring,
	const t_option *longopts,
	int *longindex
)
{
	static int	short_index = 1;
	char		*opt_string_short_option;

	if (ft_optind >= argc)
		return -1;
	if (!argv[ft_optind][short_index])
	{
		ft_optind++;
		short_index = 1;
	}
	while (ft_optind < argc && !is_option(argv[ft_optind]))
		ft_optind++;
	if (ft_optind == argc)
		return -1;
	if (ft_strcmp(argv[ft_optind], "--") == 0)
	{
		move_to_front(argv, ft_optind);
		ft_optind++;
		return -1;
	}
	if (ft_strncmp(argv[ft_optind], "--", 2) == 0)
	{
		if (!longopts)
		{
			if (ft_opterr)
				ft_dprintf(2, "%s: unrecognized option '%s'\n", argv[0], argv[ft_optind]);
			ft_optopt = '?';
			ft_optind++;
			return '?';
		}
		{
			int	i;
			int	potential_long_index;

			i = 0;
			potential_long_index = -1;
			*longindex = -1;
			while (longopts[i].name)
			{
				if (ft_strcmp(longopts[i].name, argv[ft_optind] + 2))
				{
					*longindex = i;
					break;
				}
				if (ft_strncmp(longopts[i].name, argv[ft_optind] + 2, ft_strlen(longopts[i].name)) == 0)
				{
					if (potential_long_index != -1)
					{
						if (ft_opterr)
							ft_dprintf(2, "%s: option '%s' is ambiguous\n", argv[0], argv[ft_optind]);
						ft_optopt = '?';
						ft_optind++;
						return '?';
					}
					potential_long_index = i;
				}
			}
			if (potential_long_index != -1)
				*longindex = potential_long_index;
			if (*longindex == -1)
			{
				if (ft_opterr)
					ft_dprintf(2, "%s: unrecognized option '%s'\n", argv[0], argv[ft_optind]);
				ft_optopt = '?';
				ft_optind++;
				return '?';
			}
			if (longopts[*longindex].has_arg == no_argument)
			{
				if (argv[ft_optind][2 + ft_strlen(longopts[*longindex].name)])
				{
					if (ft_opterr)
						ft_dprintf(2, "%s: option '%s' doesn't allow an argument\n", argv[0], argv[ft_optind]);
					ft_optopt = longopts[*longindex].val;
					ft_optind++;
					return '?';
				}
				ft_optarg = NULL;
				ft_optind++;
				return longopts[*longindex].val;
			}
			if (argv[ft_optind][2 + ft_strlen(longopts[*longindex].name)] == '=')
			{
				ft_optarg = &argv[ft_optind][3 + ft_strlen(longopts[*longindex].name)];
				ft_optind++;
				return longopts[*longindex].val;
			}
			if (longopts[*longindex].has_arg == optional_argument)
			{
				ft_optarg = NULL;
				ft_optind++;
				return longopts[*longindex].val;
			}
			if (ft_optind + 1 < argc)
			{
				ft_optarg = argv[ft_optind + 1];
				ft_optind += 2;
				return longopts[*longindex].val;
			}
			if (ft_opterr)
				ft_dprintf(2, "%s: option '%s' requires an argument\n", argv[0], argv[ft_optind]);
			ft_optopt = longopts[*longindex].val;
			ft_optind++;
			return '?';
		}
	}
	opt_string_short_option = ft_strchr(optstring, argv[ft_optind][short_index++]);
	if (opt_string_short_option == NULL)
	{
		if (ft_opterr)
			ft_dprintf(2, "%s: illegal option -- %c\n", argv[0], argv[ft_optind][short_index]);
		ft_optopt = opt_string_short_option[0];
		return '?';
	}
	if (opt_string_short_option[1] != ':')
		return opt_string_short_option[0];
	if (argv[ft_optind][short_index])
	{
		ft_optarg = &argv[ft_optind][short_index];
		ft_optind++;
		short_index = 1;
		return opt_string_short_option[0];
	}
	else if (ft_optind + 1 < argc)
	{
		ft_optarg = argv[ft_optind + 1];
		ft_optind += 2;
		short_index = 1;
		return opt_string_short_option[0];
	}
	else
	{
		if (ft_opterr)
			ft_dprintf(2, "%s: option requires an argument -- %c\n", argv[0], opt_string_short_option[0]);
		ft_optopt = opt_string_short_option[0];
		return '?';
	}
}
