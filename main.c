#include "libasm.h"

static size_t check_len(char* word)
{
    return (ft_strlen(word));
}

static char* now_copy(char* word, size_t len)
{
    char *dst;

    dst = malloc(len + 1);
    return (ft_strcpy(dst, word));
}

static int compare(char* s1, char* s2)
{
    return (ft_strcmp(s1, s2));
}

static char* dup_impostor(char* clone)
{
    return (ft_strdup(clone));
}

static void write_it_all(char* s1, char* s2)
{
    int fd;

    fd = 0; 
    fd = open("PudaFile.txt", O_WRONLY | O_CREAT);
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

    char*   word;
    size_t  len;
    char*   clone;
    int     cmp;
    char*   dup;
    char*   impostor;
    word = "Puda";
    len = 0;
    clone = NULL;
    impostor = "Pupuda";
    cmp = 0;
    dup = NULL;

    len = check_len(word);
    printf("My name is %s ...and my size is %ld\n",word, len);
    
    clone = now_copy(word, len);
    printf("I am the original %s, and this is my clone: %s\n", word, clone);
    
    cmp = compare(word, clone);
    printf("My clone and I compare are: %d\n", cmp);
    cmp = compare(impostor, word);
    printf("Maybe there is an impostor here: %d\n", cmp);

    dup = dup_impostor(impostor);
    printf("dup result: %s\n", dup);
    
    write_it_all(word, impostor);

    read_the_file();
    free(dup);
    free (clone);
    //tests();
    return 0;

}