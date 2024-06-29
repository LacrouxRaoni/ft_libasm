#include "libasm.h"

void test_strlen()
{
    char*   word;
    size_t  len;

    printf("############ TEST STRLEN ############\n");

    word = "Puda";
    len = ft_strlen(word);
    printf("size of %s in ft_strlen is %ld\n", word ,len);
    len = strlen(word);
    printf("size of %s in strlen is %ld\n\n", word ,len);

    word = "Raoni";
    len = ft_strlen(word);
    printf("size of %s in ft_strlen is %ld\n", word ,len);
    len = strlen(word);
    printf("size of %s in strlen is %ld\n\n", word ,len);

    word = "Raoni\n\n\n\nPuda";
    len = ft_strlen(word);
    printf("size of %s in ft_strlen is %ld\n", word ,len);
    len = strlen(word);
    printf("size of %s in strlen is %ld\n\n", word ,len);

    word = "42";
    len = ft_strlen(word);
    printf("size of %s in ft_strlen is %ld\n", word ,len);
    len = strlen(word);
    printf("size of %s in strlen is %ld\n\n", word ,len);

    word = "";
    len = ft_strlen(word);
    printf("size of %s in ft_strlen is %ld\n", word ,len);
    len = strlen(word);
    printf("size of %s in strlen is %ld\n\n", word ,len);

    word = NULL;
    len = ft_strlen(word);
    printf("size of %s in ft_strlen is %ld\n", word ,len);
    //len = strlen(word);
    //printf("size of %s in strlen is %ld\n\n", word ,len);
    
    printf("############ END TEST STRLEN ############\n\n\n");
}

void test_strcmp()
{
    char    *s1;
    char    *s2;
    int     cmp;

    printf("############ TEST STRCMP ############\n");

    cmp = 0;
    s1 = "apple";
    s2 = "apple";

    cmp = ft_strcmp(s1, s2);
    printf("result in ft_strcmp when values are equal: %d\n", cmp);
    cmp = strcmp(s1, s2); 
    printf("result in strcmp when values are equal: %d\n\n", cmp);

    s1 = "apple pie";
    s2 = "apple";

    cmp = ft_strcmp(s1, s2);
    printf("result in ft_strcmp when value in s1 is bigger than in s2: %d\n", cmp);
    cmp = strcmp(s1, s2); 
    printf("result in strcmp when value in s1 is bigger than in s2 %d\n\n", cmp);

    s1 = "apple";
    s2 = "apple pie";

    cmp = ft_strcmp(s1, s2);
    printf("result in ft_strcmp when value in s1 is lower than in s2: %d\n", cmp);
    cmp = strcmp(s1, s2); 
    printf("result in strcmp when value in s1 is lower than in s2 %d\n\n", cmp);

    s1 = NULL;
    s2 = NULL;

    cmp = ft_strcmp(s1, s2);
    printf("result in ft_strcmp when value in s1 or s2 is null: %d\n", cmp);
    //cmp = strcmp(s1, s2); 
    //printf("result in strcmp when value in s1 is lower than in s2 %d\n\n", cmp);

    printf("############ END TEST STRLEN ############\n\n\n");
}

int main(void)
{
    test_strlen();
    
    test_strcmp();
    





    return 0;


}