#include <stdio.h>
#include "libft.h"

int	ft_calc_num_separators(char const *s, char c, int count)
{
	char	*res;

	res = ft_strchr(s, c);
	if (res == NULL)
		return (count);
	count++;
	res = ft_substr(res, 1, ft_strlen(res) - 1);
	printf("RES is .%s.\n", res);
	return (ft_calc_num_separators(res, c, count));

}

char **ft_split(char const *s, char c)
{
	char	**result;

	printf("Original is: .%s.\n", s);
	printf("Separator count is %d\n", ft_calc_num_separators(s, c, 0));

	return ({"ciao", "ciao", NULL;});
}
