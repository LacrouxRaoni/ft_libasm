#include "../libasm.h"

static void test_strlen()
{
    char*   word;
    size_t  len;

    printf("############ TEST STRLEN ############\n");

    word = "Puda";
    len = 0;
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

static void test_strcmp()
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

static void    test_strcpy()
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

void test_strdup()
{
    printf("############ TEST STRDTUP ############\n");
    
    printf("test1: standard strdup usage:\n");
    const char* src_test1 = "Pudim";
    char* dst_test1;

    dst_test1 = ft_strdup(src_test1);

    printf("str dup test1: %s\n\n", dst_test1);
    free(dst_test1);

    printf("test2: send NULL paramater to strdup:\n");
    const char* src_test2 = NULL;
    char* dst_test2;

    dst_test2 = ft_strdup(src_test2);

    printf("str dup test2: %s\n\n", dst_test2);

    printf("test3: send empty paramater to strdup:\n");
    const char* src_test3 = "";
    char* dst_test3;

    dst_test3 = ft_strdup(src_test3);

    printf("str dup test3: %s\n\n", dst_test3);
    free(dst_test3);

    printf("test4: send a big data paramater to strdup:\n");
    const char* src_test4 = "Today is the greatest day I've ever known\n"
               "Can't live for tomorrow, tomorrow's much too long\n"
               "I'll burn my eyes out\n"
               "Before I get out\n"
               "I wanted more\n"
               "Than life could ever grant me\n"
               "Bored by the chore\n"
               "Of saving face\n"
               "Today is the greatest day I've ever known\n"
               "Can't wait for tomorrow, I might not have that long\n"
               "I'll tear my heart out\n"
               "Before I get out\n"
               "Pink ribbon scars that never forget\n"
               "I tried so hard to cleanse these regrets\n"
               "My angel wings were bruised and restrained\n"
               "My belly stings\n"
               "Today is\n"
               "Today is\n"
               "Today is the greatest day, ooh\n"
               "Ooh, yeah, yeah, ooh\n"
               "I wanna turn you on\n"
               "I wanna turn you on\n"
               "I wanna turn you on\n"
               "I wanna turn you\n"
               "Today is the greatest\n"
               "Today is the greatest day\n"
               "Today is the greatest day that I have ever really known";

    char* dst_test4;

    dst_test4 = ft_strdup(src_test4);

    printf("str dup test4: %s\n\n", dst_test4);
    free(dst_test4);



    printf("############ END TEST STRDUP ############\n\n\n");    
}

static void test_write()
{
    printf("############ TEST WRITE ############\n");

    printf("TEST 1: send a string to write with negative fd:\n");
    char* test1 = "Test 1\n";
    int fd_test1 = -1;
    size_t buffsize_test1 = 7;
    ssize_t ret_test1;

    ret_test1 = write(fd_test1, test1, buffsize_test1);
    printf ("TEST 1 - write result: %zd\n", ret_test1);
    printf("TEST 1 - write errno: %d\n", errno);

    ret_test1 = ft_write(fd_test1, test1, buffsize_test1);
    printf ("TEST 1 - ft_write result: %zd\n", ret_test1);
    printf("TEST 1 - ft_write Errno: %d\n\n", errno);


    printf("TEST 2: send a string to write with negative buffer size:\n");
    char* test2 = "Test 2\n";
    int fd_test2 = 0;
    size_t buffsize_test2 = -1;
    ssize_t ret_test2;

    ret_test2 = write(fd_test2, test2, buffsize_test2);
    printf ("TEST 2 - write result: %zd\n", ret_test2);
    printf("TEST 2 - write errno: %d\n", errno);

    ret_test2 = ft_write(fd_test2, test2, buffsize_test2);
    printf ("TEST 2 - ft_write result: %zd\n", ret_test2);
    printf("TEST 2 - ft_write Errno: %d\n\n", errno);

    printf("TEST 3: send a string to write with NULL value and 0 buff size:\n");
    char* test3 = NULL;
    int fd_test3 = 0;
    size_t buffsize_test3 = 0;
    ssize_t ret_test3;

    ret_test3 = write(fd_test3, test3, buffsize_test3);
    printf ("TEST 3 - write result: %zd\n", ret_test3);
    printf("TEST 3 - write errno: %d\n", errno);

    ret_test3 = ft_write(fd_test3, test3, buffsize_test3);
    printf ("TEST 3 - ft_write result: %zd\n", ret_test3);
    printf("TEST 3 - ft_write Errno: %d\n\n", errno);

    printf("TEST 4: send a string to write with NULL value and buff size 5:\n");
    char* test4 = NULL;
    int fd_test4 = 0;
    size_t buffsize_test4 = 5;
    ssize_t ret_test4;

    ret_test4 = write(fd_test4, test4, buffsize_test4);
    printf ("TEST 4 - write result: %zd\n", ret_test4);
    printf("TEST 4 - write errno: %d\n", errno);

    ret_test4 = ft_write(fd_test4, test4, buffsize_test4);
    printf ("TEST 4 - ft_write result: %zd\n", ret_test4);
    printf("TEST 4 - ft_write Errno: %d\n\n", errno);

    printf("TEST 5: send a string to write with buff size lower:\n");
    char* test5 = "Writing test 5\n";
    int fd_test5 = 0;
    size_t buffsize_test5 = 5;
    ssize_t ret_test5;

    ret_test5 = write(fd_test5, test5, buffsize_test5);
    printf ("\nTEST 5 - write result: %zd\n", ret_test5);
    printf("TEST 5 - write errno: %d\n", errno);

    ret_test5 = ft_write(fd_test5, test5, buffsize_test5);
    printf ("\nTEST 5 - ft_write result: %zd\n", ret_test5);
    printf("TEST 5 - ft_write Errno: %d\n\n", errno);

    printf("TEST 6: send a string to write with buff size higher:\n");
    char* test6 = "Writing test 6\n";
    int fd_test6 = 0;
    size_t buffsize_test6 = 20;
    ssize_t ret_test6;

    ret_test6 = write(fd_test6, test6, buffsize_test6);
    printf ("\nTEST 6 - write result: %zd\n", ret_test6);
    printf("TEST 6 - write errno: %d\n", errno);

    ret_test6 = ft_write(fd_test6, test6, buffsize_test6);
    printf ("\nTEST 6 - ft_write result: %zd\n", ret_test6);
    printf("TEST 6 - ft_write Errno: %d\n\n", errno);

    printf("TEST 7: send a string to write with invalid fd:\n");
    char* test7 = "Writing test 7\n";
    int fd_test7 = 100;
    size_t buffsize_test7 = 15;
    ssize_t ret_test7;

    ret_test7 = write(fd_test7, test7, buffsize_test7);
    printf ("\nTEST 7 - write result: %zd\n", ret_test7);
    printf("TEST 7 - write errno: %d\n", errno);

    ret_test7 = ft_write(fd_test7, test7, buffsize_test7);
    printf ("\nTEST 7 - ft_write result: %zd\n", ret_test7);
    printf("TEST 7 - ft_write Errno: %d\n\n", errno);

    printf("TEST 8: send a string with all valid:\n");
    char* test8 = "Writing test 8\n";
    int fd_test8 = 0;
    size_t buffsize_test8 = 15;
    ssize_t ret_test8;

    ret_test8 = write(fd_test8, test8, buffsize_test8);
    printf ("\nTEST 8 - write result: %zd\n", ret_test8);
    printf("TEST 8 - write errno: %d\n", errno);

    ret_test8 = ft_write(fd_test8, test8, buffsize_test8);
    printf ("\nTEST 8 - ft_write result: %zd\n", ret_test8);
    printf("TEST 8 - ft_write Errno: %d\n\n", errno);

    printf("TEST 9: send a string with all valid to a file:\n");
    char* test9 = "Writing test 9\n";
    int fd_test9 = open("test9.txt", O_WRONLY | O_CREAT);
    size_t buffsize_test9 = 15;
    ssize_t ret_test9;

    ret_test9 = write(fd_test9, test9, buffsize_test9);
    printf ("\nTEST 9 - write result: %zd\n", ret_test9);
    printf("TEST 9 - write errno: %d\n", errno);

    ret_test9 = ft_write(fd_test9, test9, buffsize_test9);
    printf ("\nTEST 9 - ft_write result: %zd\n", ret_test9);
    printf("TEST 9 - ft_write Errno: %d\n\n", errno);
    close(fd_test9);

    printf("############ END TEST WRITE ############\n\n\n");    
}

void test_read()
{
    printf("############ TEST READ ############\n");    
    printf("TEST 1: send a text from a file to read:\n");
    char test1[128];
    int fd_test1;
    ssize_t ret_test1;

    fd_test1 = open("test9.txt", O_CREAT | O_RDONLY);    
    ret_test1 = read(fd_test1, test1, sizeof(test1));
    test1[ret_test1] = '\0'; 
    printf ("\nTEST 1 - read result: %zd\n", ret_test1);
    printf("TEST 1 - read errno: %d\n", errno);
    printf("Read content: %s\n", test1);
    close(fd_test1);

    fd_test1 = open("test9.txt", O_RDONLY);    
    ret_test1 = ft_read(fd_test1, test1, sizeof(test1));
    test1[ret_test1] = '\0'; 
    printf ("\nTEST 1 - ft_read result: %zd\n", ret_test1);
    printf("TEST 1 - ft_read Errno: %d\n\n", errno);
    printf("Read content: %s\n\n", test1);
    close(fd_test1);

    printf("TEST 2: send a negative fd to read:\n");
    char test2[128];
    int fd_test2;
    ssize_t ret_test2;

    fd_test2 = -10;
    ret_test2 = read(fd_test2, test2, sizeof(test2));
    
    test2[ret_test2] = '\0'; 
    printf ("\nTEST 2 - read result: %zd\n", ret_test2);
    printf("TEST 2 - read errno: %d\n", errno);
    
    printf("Read content: %s\n", test2);
    
    ret_test2 = ft_read(fd_test2, test2, sizeof(test2));
    test2[ret_test2] = '\0'; 
    printf ("\nTEST 2 - ft_read result: %zd\n", ret_test2);
    printf("TEST 2 - ft_read Errno: %d\n\n", errno);
    printf("Read content: %s\n\n", test2);

    printf("TEST 3: send a text from a file to read with buffer with lower size:\n");
    char test3[128];
    int fd_test3;
    ssize_t ret_test3;

    fd_test3 = open("test9.txt", O_CREAT | O_RDONLY);    
    ret_test3 = read(fd_test3, test3, 1);
    test3[ret_test3] = '\0'; 
    printf ("\nTEST 3 - read result: %zd\n", ret_test3);
    printf("TEST 3 - read errno: %d\n", errno);
    printf("Read content: %s\n", test3);
    close(fd_test3);

    fd_test3 = open("test9.txt", O_RDONLY);    
    ret_test3 = ft_read(fd_test3, test3, 1);
    test3[ret_test3] = '\0'; 
    printf ("\nTEST 3 - ft_read result: %zd\n", ret_test3);
    printf("TEST 3 - ft_read Errno: %d\n\n", errno);
    printf("Read content: %s\n\n", test3);
    close(fd_test3);

    printf("TEST 4: send a text from a file to read with buffer with an invalid fd:\n");
    char test4[128];
    int fd_test4;
    ssize_t ret_test4;

    fd_test4 = 100;    
    ret_test4 = read(fd_test4, test4, sizeof(test4));
    test4[ret_test4] = '\0'; 
    printf ("\nTEST 4 - read result: %zd\n", ret_test4);
    printf("TEST 4 - read errno: %d\n", errno);
    printf("Read content: %s\n", test4);


    fd_test4 = 100;    
    ret_test4 = ft_read(fd_test4, test4, sizeof(test4));
    test4[ret_test4] = '\0'; 
    printf ("\nTEST 4 - ft_read result: %zd\n", ret_test4);
    printf("TEST 4 - ft_read Errno: %d\n\n", errno);
    printf("Read content: %s\n\n", test4);


    printf("############ END TEST READ ############\n\n\n");    
}

void tests()
{
    test_strlen();
        
    test_strcmp();
    
    test_strcpy();

    test_strdup();

    test_write();
 
    test_read();

}