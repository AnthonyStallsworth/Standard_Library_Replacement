#include "string.h"
#include "mem_alloc.h"

int main()
{

	char foo[] = "foo";
	String str = charArr_toString(foo, 3);
	printf("%d\n", str.length);

	for(int i = 0; i < str.length; i++)
	{
		printf("%c", charAt(&str, i));
	}
	printf("%c\n", ' ');
	while(1)
	{
		allocate_page();
	}
	

	return 0;
}