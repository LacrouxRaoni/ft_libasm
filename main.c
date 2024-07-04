#include "libasm.h"
#include <stdlib.h>

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

    printf("############ END TEST STRCMP ############\n\n\n");
}

void    test_strcpy()
{

    printf("############ TEST STRCPY ############\n");

    //test with src null
    printf("test1: src with null:\n");
    char *test1_src;
    char *test1_dst;
    char *test1_ret;

    test1_src = NULL;
    test1_dst = "";
    test1_ret = "";
    printf("before: \ntest1_src: %p\ntest1_dst: %p\ntest1_ret: %s\n\n",test1_src, test1_dst, test1_ret);
    test1_ret = ft_strcpy(test1_dst, test1_src);
    printf("after: \ntest1_src: %p\ntest1_dst: %p\ntest1_ret: %s\n\n",test1_src, test1_dst, test1_ret);

    //test with dst null
    printf("test2: dst with null:\n");
    char *test2_src;
    char *test2_dst;
    char *test2_ret;

    test2_src = "Test2";
    test2_dst = NULL;
    test2_ret = "";
    printf("before: \ntest2_src: %s\ntest2_dst: %p\ntest2_ret: %s\n\n",test2_src, test2_dst, test2_ret);
    test2_ret = ft_strcpy(test2_dst, test2_src);
    printf("after: \ntest2_src: %s\ntest2_dst: %p\ntest2_ret: %s\n\n",test2_src, test2_dst, test2_ret);


    //test with src and dst null
    printf("test3: src and dst with null:\n");
    char *test3_src;
    char *test3_dst;
    char *test3_ret;

    test3_src = NULL;
    test3_dst = NULL;
    test3_ret = "";
    printf("before: \ntest3_src: %p\ntest3_dst: %p\ntest3_ret: %s\n\n",test3_src, test3_dst, test3_ret);
    test3_ret = ft_strcpy(test3_dst, test3_src);
    printf("after: \ntest3_src: %p\ntest3_dst: %p\ntest3_ret: %s\n\n",test3_src, test3_dst, test3_ret);


    //test with src empty
    printf("test4: src empty:\n");
    char *test4_src;
    char test4_dst[1];
    char *test4_ret;

    test4_src = "";
    test4_ret = "";
    printf("before: \ntest4_src: %s\ntest4_dst: %s\ntest4_ret: %s\n\n",test4_src, test4_dst, test4_ret);
    test4_ret = ft_strcpy(test4_dst, test4_src);
    printf("after: \ntest4_src: %s\ntest4_dst: %s\ntest4_ret: %s\n\n",test4_src, test4_dst, test4_ret);


    //test src with string and dst without enouth size
    printf("test5: dst without necessary size:\n");
    char *test5_src;
    char test5_dst[1];
    char *test5_ret;

    test5_src = "Test 5";
    test5_ret = "";
    printf("before: \ntest5_src: %s\ntest5_dst: %s\ntest5_ret: %s\n\n",test5_src, test5_dst, test5_ret);
    test5_ret = ft_strcpy(test5_dst, test5_src);
    printf("after: \ntest5_src: %s\ntest5_dst: %s\ntest5_ret: %s\n\n",test5_src, test5_dst, test5_ret);

    //test dst with enought size
    printf("test6: dst with enought size:\n");
    char *test6_src;
    char test6_dst[6] = {""};
    char *test6_ret;

    test6_src = "Test 6";
    test6_ret = "";
    printf("before: \ntest6_src: %s\ntest6_dst: %s\ntest6_ret: %s\n\n",test6_src, test6_dst, test6_ret);
    test6_ret = ft_strcpy(test6_dst, test6_src);
    printf("after: \ntest6_src: %s\ntest6_dst: %s\ntest6_ret: %s\n\n",test6_src, test6_dst, test6_ret);

    //test dst with data already and with the right size
    printf("test7: dst with data already and with the right size:\n");
    char *test7_src;
    char test7_dst[6] = {"Test 6"};
    char *test7_ret;

    test7_src = "Test 7";
    test7_ret = "";
    printf("before: \ntest7_src: %s\ntest7_dst: %s\ntest7_ret: %s\n\n",test7_src, test7_dst, test7_ret);
    test7_ret = ft_strcpy(test7_dst, test7_src);
    printf("after: \ntest7_src: %s\ntest7_dst: %s\ntest7_ret: %s\n\n",test7_src, test7_dst, test7_ret);

    printf("############ END TEST STRCPY ############\n\n\n");    

}

int main(void)
{
    test_strlen();
        
    test_strcmp();
    
    test_strcpy();

    return 0;


}