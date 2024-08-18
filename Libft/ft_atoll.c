/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:09:34 by sylabbe           #+#    #+#             */
/*   Updated: 2024/07/10 09:59:42 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlen_atoll(const char *str, long long int res);

long long int	ft_atoll(const char *str, int *overflow)
{
	long long int	res;
	int				i;
	char			sgn;

	res = 0;
	i = 0;
	sgn = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48);
	res *= sgn;
	if (ft_strlen_atoll(str, res) || (sgn == -1 && res > 0) || (sgn == 1
			&& res < 0))
		*overflow = 1;
	return (res);
}

// Return 0 if n equal 0,
int	ft_nbrlen(long long int n)
{
	int	count_int;

	count_int = 0;
	while (n != 0)
	{
		n /= 10;
		count_int++;
	}
	return (count_int);
}

int	ft_strlen_atoll(const char *str, long long int res)
{
	int	i;
	int	count_str;
	int	count_int;

	i = 0;
	count_str = 0;
	count_int = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		i++;
		count_str++;
	}
	count_int = ft_nbrlen(res);
	if (count_int == count_str)
		return (0);
	else
		return (1);
}
