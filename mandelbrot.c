#include <stdio.h>
#include <unistd.h>
# define MAX_ITER 40
typedef     struct t_list
{
    double img;
    double ree;
}s_list;
double      convert_to_complex(int      pixel_cor, double screen_max, double complex_min, double complex_nax)
{
    double  value1 = pixel_cor / screen_max;
    double  value2 = complex_nax - complex_min;
    return (complex_min + value1 * value2);
}
void        draw_mandelbrot(int x, int y)
{
    int     i;
    i = 0;
    s_list      z;
    s_list      c;
    z.ree = 0;
    z.img = 0;
    c.img = convert_to_complex (x, 800, -2, 2);
    c.ree = convert_to_complex (y, 800, 2, -2);
    while (i <= MAX_ITER)
    {
        double      sqr = 
        sqr = 
    }
}

int main()
{

}
