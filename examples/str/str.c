#include <str.h>
#include <obj.h>
#include <stdio.h>

int main() {
	str str;
	make_at(str, str_t) from(0);

	str_push_back_cstr(&str, "Hello ", 6);
	str_push_back_cstr(&str, "World" , 5);
	str_pop_at		  (&str, 5, 6);
	printf("Bool : %s\n", ptr_raw(str_ptr(&str)));

	del(&str);
}