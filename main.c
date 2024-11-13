#include "libasm.h"

static void test_ft_strlen()
{
    size_t len;

    len = ft_strlen("My size is 13");
    printf("len: %ld\n", len);

    len = ft_strlen("");
    printf("len: %ld\n", len);

    len = ft_strlen("Some say the end is near\n"
        "Some say we'll see Armageddon soon\n"
        "I certainly hope we will\n"
        "I sure could use a vacation from this\n"
        "Bullshit three-ring\n"
        "Circus sideshow of\n"
        "Freaks\n"
        "Here in this hopeless fucking hole we call L.A.\n"
        "The only way to fix it is to flush it all away\n"
        "Any fucking time, any fucking day\n"
        "Learn to swim, I'll see you down in Arizona bay\n"
        "Fret for your figure and\n"
        "Fret for your latte and\n"
        "Fret for your lawsuit and\n"
        "Fret for your hairpiece and\n"
        "Fret for your Prozac and\n"
        "Fret for your pilot and\n"
        "Fret for your contract and\n"
        "Fret for your car\n"
        "It's a\n"
        "Bullshit three-ring\n"
        "Circus sideshow of\n"
        "Freaks\n"
        "Here in this hopeless fucking hole we call L.A.\n"
        "The only way to fix it is to flush it all away\n"
        "Any fucking time, any fucking day\n"
        "Learn to swim, I'll see you down in Arizona bay\n"
        "Some say a comet will fall from the sky\n"
        "Followed by meteor showers and tidal waves\n"
        "Followed by fault lines that cannot sit still\n"
        "Followed by millions of dumbfounded dipshits\n"
        "And some say the end is near\n"
        "Some say we'll see Armageddon soon\n"
        "I certainly hope we will\n"
        "I sure could use a vacation from this\n"
        "Stupid shit, silly shit, stupid shit\n"
        "One great big festering neon distraction\n"
        "I've a suggestion to keep you all occupied\n"
        "Learn to swim, learn to swim, learn to swim\n"
        "'Cause Mom's gonna fix it all soon\n"
        "Mom's comin' 'round to put it back the way it ought to be\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Fuck L. Ron Hubbard and\n"
        "Fuck all his clones\n"
        "Fuck all these gun-toting\n"
        "Hip gangster wannabes\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Fuck retro anything\n"
        "Fuck your tattoos\n"
        "Fuck all you junkies and\n"
        "Fuck your short memories\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Yeah, fuck smiley glad-hands\n"
        "With hidden agendas\n"
        "Fuck these dysfunctional\n"
        "Insecure actresses\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "Learn to swim, learn to swim\n"
        "'Cause I'm praying for rain\n"
        "I'm praying for tidal waves\n"
        "I wanna see the ground give way\n"
        "I wanna watch it all go down\n"
        "Mom, please flush it all away\n"
        "I wanna see it go right in and down\n"
        "I wanna watch it go right in\n"
        "Watch you flush it all away\n"
        "Yeah, time to bring it down again\n"
        "Yeah, don't just call me pessimist\n"
        "Try and read between the lines\n"
        "I can't imagine why you wouldn't\n"
        "Welcome any change, my friend\n"
        "I wanna see it come down\n"
        "Put it down\n"
        "Suck it down\n"
        "Flush it down\n");
    printf("len: %ld\n", len);
}

void test_ft_strcmp()
{
    int cmp; 

    cmp = ft_strcmp("Teste0", "Teste0");
    printf("cmp: %d\n", cmp);

    cmp = ft_strcmp("Teste0", "Teste9");
    printf("cmp: %d\n", cmp);
    cmp = ft_strcmp("Teste9", "Teste0");
    printf("cmp: %d\n", cmp);

    cmp = ft_strcmp("", "0");
    printf("cmp: %d\n", cmp);

    cmp = ft_strcmp("0", "");
    printf("cmp: %d\n", cmp);
}

void test_ft_strcpy()
{
    char* copy;
    char* dest;
    
    dest = malloc(ft_strlen("Hello World") * sizeof(char) + 1);
    copy = ft_strcpy(dest, "Hello World");
    printf("copy: %s\n", copy);
    free(dest);
}

void test_ft_write()
{
    ft_write(0, "Writing Hello World\n", ft_strlen("Writing Hello World\n"));
    ft_write(0, "Writing Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld\n", ft_strlen("Writing Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld\n"));
    ft_write(0, "", ft_strlen(""));

    int fd = open("Test.txt", O_WRONLY | O_CREAT);
    ft_write(fd, "Writing Hello World\n", ft_strlen("Writing Hello World\n"));
}

void test_ft_read()
{
    char* buffer;

    buffer = calloc(sizeof(char) * 1024, sizeof(char));
    ft_read(1, buffer, sizeof(char) * 1024);
    printf("read: %s\n", buffer);
	if (buffer != NULL)
		free (buffer);
}

void test_ft_strdup()
{
    char* dup;

    dup = ft_strdup("Here is dupped");
    printf("dup: %s\n", dup);
	free(dup);
}

int main(void)
{
	
    printf ("====FT_STRLEN====\n");
    test_ft_strlen();

    printf ("====FT_STRCMP====\n");
    test_ft_strcmp();

    printf ("====FT_STRCPY====\n");
    test_ft_strcpy();

    printf ("====FT_WRITE====\n");
    test_ft_write();

    printf ("====FT_READ====\n");
    test_ft_read();

    printf ("====FT_STRDUP====\n");
    test_ft_strdup();
	
    return 0;

}