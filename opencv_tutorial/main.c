#include <stdio.h>
#include <stdlib.h>

int img_display(char *v);
int blur_image(char *s);

int main(int argc, char **argv)
{
    int arg1 = atoi(argv[1]);
    char *file_path = argv[2];

    if (arg1 == 1)
    {
        int result = img_display( file_path );
        printf("the result is: %d\n", result);
    } else {
        int result = blur_image( file_path );
        printf("The return result is %d\n", result);
    }

    // int result = img_display(file_path);
    // int blur_result = 
    // printf("%d",result);
    // int result = blur_image( file_path );
    // printf("The return result is %d\n", result);
    // puts("image is done!");
    return 0;
}
