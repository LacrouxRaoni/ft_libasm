#include "libasm.h"

void test_len()
{
    int     number;
    char*   word;
    size_t  len;

    word = "Puda";
    len = ft_strlen(word);
    printf("size of %s is %ld\n", word ,len);
    
    word = "Raoni";
    len = ft_strlen(word);
    printf("size of %s is %ld\n", word ,len);

    word = "Raoni\n\n\n\nPuda";
    len = ft_strlen(word);
    printf("size of %s is %ld\n", word ,len);

    word = "42";
    len = ft_strlen(word);
    printf("size of %s is %ld\n", word ,len);

    word = "";
    len = ft_strlen(word);
    printf("size of %s is %ld\n", word ,len);
    
}

int main(void)
{
    test_len();
    



    return 0;


}