/****************************************************
* This is an implementation of safe strings. It     *
* might make things easier for you. It should be    *
* very secure. The only time your strings should    *
* mess up is if you manually mess them up after     *
* creation by inserting a null character somewhere  *
* it should not go. But of course you wont do that. *
****************************************************/

#ifndef STRING
#define STRING

/* The String (wrapper of a character array) */
typedef struct {
	int length;
	char* value;
} String;

/****************************************************
* Without the use of malloc, this will do a shallow *
* copy of the character array you pass through.     *
****************************************************/
String charArr_toString(char* x, int len)
{
	/* null string in case we return an error */
	char* null = '\0';
	String NULL;

	NULL.length = 0;
	NULL.value = null;

	/* Make sure the string does not contain a null character */
	for(int i = 0; i < len; i++)
		if(x[i] == '\0') return NULL;

	/* Make sure the array ends with a null character */
	if(x[len] != '\0') return NULL;

	String s;
	s.length = len;
	s.value = x;

	return s;
}

/****************************************************
* Gets you the character at a specific location in  *
* the character array                               *
****************************************************/
char charAt(String* str, int pos)
{
	/* Make sure the position is greater than 0 */
	if(pos < 0) return '\0';

	/* Make sure the position is less than the length of the String */
	if(pos >= str->length) return '\0';

	return str->value[pos];
}



#endif