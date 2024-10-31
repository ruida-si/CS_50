#include <unistd.h>

int arg_comp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}

void print(int argc, char *argv[])
{
    int j = 1;
    while (j < argc)
    {
        int i = 0;
        while (argv[j][i])
        {
            write(1, &argv[j][i], 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
    }
}
int main(int argc, char *argv[])
{
    int j = 1;
    while (j < argc)
    {
        int i = 1;
        while (i < argc -1)
        {
            if (arg_comp(argv[i], argv[i +1]) > 0)
            {
                char *temp = argv[i];
                argv[i] = argv[i +1];
                argv[i +1] = temp;
            }
            i++;
        }
        j++;
    }
    print(argc, argv);
}
