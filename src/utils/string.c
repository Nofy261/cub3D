/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:57:21 by rraumain          #+#    #+#             */
/*   Updated: 2025/07/04 16:15:43 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	char_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcspn(char *line, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (str[j])
		{
			if (line[i] == str[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

char	*skip_whitespaces(char *str)
{
	while (str && is_whitespace(*str))
		str++;
	return (str);
}

int	count_words(const char *s)
{
	int	i;
	int	count ;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !is_whitespace(s[i]))
			i++;
	}
	return (count);
}
