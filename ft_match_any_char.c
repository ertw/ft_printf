int	match_any_char(char *str, char c)
{
	if (str && *str)
	{
		if (*str == c)
			return (1);
		return (match_any_char(++str, c));
	}
	return (0);
}
