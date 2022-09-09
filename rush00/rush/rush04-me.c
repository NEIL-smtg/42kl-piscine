#include <unistd.h>

void ft_putchar(char ch)
{
    write(1, &ch, 1);
}

void checkPoint(int x, int y, int cx, int cy)
{
    if ((cx == 1 && cy == 1) || (cx == x && cy == y && y > 1 && x > 1))
    {
        ft_putchar('A');
    }
	else if ((cx == x && cy == 1) || (cx == 1 && cy == y))
    {
        ft_putchar('C');
    }
    else if( cx > 1 && cx < x && (cy == 1 || cy == y))
	{
		ft_putchar('B');
	}
	else if( cy > 1 && cy < y && (cx == 1 || cx == x))
	{
		ft_putchar('B');
	}
    else
    {
        ft_putchar(' ');
    }
}

void rush(int x, int y)
{
    int cx;
    int cy;

    cx = 0;
    cy = 0;
    while (++cy <= y)
    {
        cx = -1;
        while (++cx <= x)
        {
            checkPoint(x, y , cx, cy);
        }
        ft_putchar('\n');
    }
}

int main(void)
{
    rush(5,3);
    return 0;
}