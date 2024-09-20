#include "../includes/so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

static int	count_digits(long nb)
{
	int	result;

	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	result = 0;
	while (nb != 0)
	{
		result++;
		nb = nb / 10;
	}
	return (result);
}

static void	fill_str(char *str, int digits, long nb)
{
	int	i;

	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
		digits++;
	}
	i = digits;
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return ;
	}
	while (i > 0 && nb > 0)
	{
		str[--i] = (nb % 10) + 48;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		sign;
	long	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
		sign = 1;
	digits = count_digits(nb);
	str = (char *)malloc((digits + sign + 1) * sizeof(char));
	if (str == 0)
		return (0);
	fill_str(str, digits, nb);
	return (str);
}

char	*ft_strchr(const char *string, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (string[i] != '\0')
	{
		if (string[i] == ch)
			return ((char *)(string + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(string + i));
	return (0);
}

int	ft_strlen(const char *string)
{
	int	len;

	len = 0;
	while (string[len] != '\0')
	{
		len++;
	}
	return (len);
}
