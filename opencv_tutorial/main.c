#include <stdio.h>
#include "display_image.h"

int main(int argc, char **argv)
{
    char *file_path = argv[1];
    int result = display_image(file_path);
    printf("%d",result);
    puts("image is done!");
    return 0;
}
