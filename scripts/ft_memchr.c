
void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	const char *buffer;
	
	i = 0;
	buffer = s;
	while (i < n && buffer[i] != c)
	{
		i++;
	}
	if (buffer[i] == c)
		return &buffer[i];
	return NULL;
}