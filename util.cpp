#include "util.h"
#include "heap.h"
#include <stdio.h>
int nextCommand(int *i, int *v, int *f, int *n, int *k)
{
	char c;
	while (1)
	{
		scanf_s("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		if (c == 'S' || c == 'R' || c == 'W' || c == 's' || c == 'r' || c == 'w') {
			break;
		}
		if (c == 'K' || c == 'k') {
			scanf_s("%d", i);
			scanf_s("%d", v);
			scanf_s("%d", f);
			break;
		}
		if (c == 'C' || c == 'c') {
			scanf_s("%d", n);
			break;
		}
		if (c == 'I' || c == 'i')
		{
			scanf_s("%d", k);
			scanf_s("%d", f);
			break;
		}
		printf("Invalid Command\n");
	}
	return c;
}