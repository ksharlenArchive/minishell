#include "minishell.h"

static int	ft_num_str(const char *p_str, char sym)
{
	int		ret;

	ret = 0;
	if (p_str && *p_str)
	{
		while (p_str && *p_str)
		{
			p_str = ft_skiptabs(p_str);
			if (p_str && *p_str && (*p_str != sym))
				++ret;
			p_str = ft_skip_before(p_str, sym);
		}
	}
	return (ret);
}

static char		*ft_alloc_before(char **str, char sym)
{
	size_t		len;
	char		*ret_str;

	ret_str = NULL;
	if (*str && **str)
	{
		len = ft_strnlen(*str, sym);
		ret_str = (char *)ft_strnew(sizeof(char) * len);
		ft_strncat(ret_str, *str, len);
		(*str) = *(str) + len;
		*str = ft_skipfirst(*str, sym);
	}
	return (ret_str);
}

static void		push_str(char *str, char *str_ret[], size_t size_str, char sym)
{
	size_t		i;

	i = 0;
	while (i < size_str - 1)
	{
		//str = ft_skiptabs(str);
		str = ft_skiptabs_sym(str, sym);
		// if (str && *str == sym)
		// 	str = ft_skipfirst(str, sym);
		ft_printf("test: %s\n", str);
		exit(EXIT_FAILURE);
		str_ret[i] = ft_alloc_before(&str, sym);
		++i;
	}
	str_ret[size_str - 1] = NULL;
}

char	**ft_strsplit_skip_space(char *str, char sym)
{
	char	**ret_str;
	int		num_str;

	ret_str = NULL;
	num_str = ft_num_str(str, sym);
	ret_str = (char **)ft_memalloc(sizeof(char *) * (num_str + 1));
	if (!ret_str)
		exit(EXIT_FAILURE);
	push_str(str, ret_str, num_str + 1, sym);
	return (ret_str);
}
