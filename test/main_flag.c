#include "main.h"
int main(void)
{
	int i = 0;
	int res = get_all_flags("%0", &i);
	printf("%d\n", res);
	return (0);
}
