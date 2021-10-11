#include "../push_swap.h"

int	ft_strncmp (char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*m1;
	unsigned char	*m2;

	i = 0;
	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (i < n)
	{
		if (m2[i] > m1[i])
			return (m1[i] - m2[i]);
		if (m1[i] > m2[i])
			return (m1[i] - m2[i]);
		if (m1[i] == '\0' && m2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
