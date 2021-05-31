#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char **argv)
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	long ret;
	ret = syscall(549, a, b);
	printf("%d + %d = %d\n",a, b, ret);

	return 0;
}
