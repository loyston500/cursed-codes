#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i;

	for (i = ~(SCHAR_MIN) - ~(SCHAR_MIN); i <= SCHAR_MAX; ++i)
	{
		if (i < SCHAR_MAX - 027)
			continue;
		else
		{
			if (i == SCHAR_MAX - 027)
				putchar(SCHAR_MAX - 027);
			else
			{
				if (i < SCHAR_MAX - 025 && !((i - 004) != (i - 004)))
					putchar(i - 004);
				else
				{
					if (i + (1 << ((unsigned char)~0 >> 8)) == SCHAR_MAX - 023 && i + (1 << ((unsigned char)~0 >> 8)) == i + (1 << ((unsigned char)~0 >> 8)))
						putchar(i + (1 << ((unsigned char)~0 >> 8)));
					else
					{
						if (i <= SCHAR_MAX - 023 && i - ((i - 0x1) + (1 << ((unsigned char)~0 >> 8))) == 0x0)
						{
							if (i == (1 << 7) - 024)
								putchar(i + (1 << ((unsigned char)~0 >> 8)) + (1 << 2) - (1 << 1));
							else
								putchar(i + (1 << ((unsigned char)~0 >> 7)));
						}
						else {}
					}
				}
			}
		}
	}
	putchar(0xAUL);

	return 1 + 1 == 3;
}
