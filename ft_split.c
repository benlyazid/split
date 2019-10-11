#include <stdio.h>

#include<stdlib.h>

//#include <libstd.h>

int     countwords(char *data, char c)
{
    int ret;
    int i;

    i = 0;
    ret = 0;
    while(data[i] != '\0')
    {
        if(data[i] == c && data[i + 1] != c)
            ret++; 
    i++;
    }
      if (data[0] != c)
            ret++;
    if (data[i - 1] != c)
            ret++;
    return (ret - 1);
}

char    *find_start(char *data, char c, int pos)
{
    int     i;
    int     j;
    char    *ret;

    i = 0;
    j = 0;
    while (j < pos)
    {
        if(data[0] != c && pos == 1)
            return (data + 0);
        if (data[i] == c && data[i + 1] != c)
            j++;
    //printf("%s\n",data + j);
        i++;
    }
    ret = &data[i];
    return (ret);
}

int size_of_words(char *data, char c)
{
    int size;

    size = 0;
    while(data[size] != c && data[size] != '\0')
        size++;
    return (size);
}

 char   **ft_split(char const *data, char c)
{
    char    **ret;
    int     number_of_words;
    int     i;
    char    *chaine_ret;
    int     size;
    int     size_total;

    i = 1;
    size_total = 0;
    number_of_words = countwords((char*)data, c);
    ret = malloc(sizeof(char*) *(number_of_words + 1));
    while (i < number_of_words + 1)
    {
        chaine_ret = find_start((char*)data,c,i);
        size = size_of_words(chaine_ret, c);
        size_total += size;
        ret[i - 1] = malloc(sizeof(char*) * (size + 1));
        ret[i - 1] = chaine_ret;
       //ret[i - 1] [size] = '\0';
        printf("%d   ",size);
        printf("%c\n",ret[i - 1][size+1]);
        i++;
    }
    return(ret);
}

int main ()
{
    char data [300] = ".P=abc.def.gt.6...9";
    ft_split(data,'.');
    return(0);
}