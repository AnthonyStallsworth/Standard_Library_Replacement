#include "string.h"
#include "macros.h"
#include "mem_alloc.h"

/* Function that tests my String */
void testString()
{
	char foo[] = "foo";
	String str = charArr_toString(foo, 3);
	printf("%d\n", str.length);

	for (int i = 0; i < str.length; i++)
	{
		printf("%c", charAt(&str, i));
	}
	printf("%c\n", ' ');
}

int main()
{
	// testString();

	while(1)
	{
		char* address;
		address = allocate_page();
		*address = '@';
	}

	return 0;
}

