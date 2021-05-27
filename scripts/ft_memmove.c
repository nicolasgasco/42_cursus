
void *ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	const char	*buffer1;
	char 	*buffer2;
	char		*temp_buffer;
	
	i = 0;
	temp_buffer = src;
	buffer1 = src;
	buffer2 = dest;
	while (i < n)
	{
		temp_buffer[i] = buffer1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		buffer2[i] = temp_buffer[i];
		i++;
	}
	return (dest);
}
