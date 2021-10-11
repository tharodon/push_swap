#include "../../push_swap.h"

char	*ft_strjoin (char const *s1, char const *s2)
{
	size_t	i;
	size_t	b;
	char	*r;

	i = 0;
	b = 0;
	r = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		r[i] = s2[b];
		i++;
		b++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strdup (const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
