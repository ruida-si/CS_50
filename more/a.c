char *ft_strcapitalize(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;

    i = 0;
    while (str[i])
    {
        if (str[i] < 47 && (str[i +1] >= 'a' && str[i +1] <= 'z'))
            str[i +1] -= 32;
        i++;
    }
    return str;
}

#include <stdio.h>

int main()
{
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_strcapitalize(str);
    printf("%s\n", str);
}
