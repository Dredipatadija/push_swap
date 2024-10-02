long long   ft_atoll(char *str)
{
    long long  result;
    size_t     i;
    int        sign;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result = result * sign;
    return (result);
}