#include <stdio.h>

int img_display(char *v);

int main(int argc, char **argv)
{
    char *file_path = argv[1];
    int result = img_display(file_path);
    // int blur_result = 
    printf("%d",result);
    puts("image is done!");
    return 0;
}
