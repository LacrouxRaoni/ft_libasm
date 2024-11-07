#include "libasm.h"

static size_t check_len(char* word)
{
    return (ft_strlen(word));
}

static char* now_copy(char* word, size_t len)
{
    char dst[len];

    return (ft_strcpy(dst, word));
}

static int compare(char* s1, char* s2)
{
    return (ft_strcmp(s1, s2));
}

static char* dup_clone(char* clone)
{
    return (ft_strdup(clone));
}

static void write_it_all(char* s1, char* s2)
{
    int fd;

    fd = open("PudaFile.txt", O_WRONLY | O_CREAT | O_APPEND);
    ft_write(fd, s1, ft_strlen(s1));
    ft_write(fd, s2, ft_strlen(s2));
    close(fd);
}

static void read_the_file()
{
    char    buffer[128];
    size_t  ret;
    int fd;

    fd = open("PudaFile.txt", O_RDONLY);
    ret = ft_read(fd, buffer, sizeof(buffer));
    buffer[ret] = '\0';

    printf("read content: %s\n", buffer);
    close (fd);
}

int main(void)
{

    char*   word = "My name is Puda";
    size_t  len;
    char*   clone;
    int     cmp;
    char*   dup;

    len = check_len(word);
    printf("%s ...and my size is %ld\n",word, len);
    
    clone = now_copy(word, len);
    printf("Now...%s, and this is my clone: %s\n", word, clone);
    
    cmp = compare(word, clone);
    printf("My clone and I compare are: %d\n", cmp);

    dup = dup_clone(word);
    printf("dup result: %s\n", dup);
    
    write_it_all(word, dup);
    
    read_the_file();
 
    //tests();
    return 0;

}