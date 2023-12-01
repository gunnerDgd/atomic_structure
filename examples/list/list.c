#include <list.h>
#include <obj.h>
#include <mem.h>

#include <stdio.h>
#include <stdlib.h>

bool_t cstd_mem_res_new() { return true_t; }
void   cstd_mem_res_del() { return true_t; }

void*  cstd_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   cstd_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res_trait cstd_mem_res_trait = {
	.on_new = &cstd_mem_res_new,
	.on_del = &cstd_mem_res_del,

	.on_mem_new = &cstd_mem_new,
	.on_mem_del = &cstd_mem_del
};

mem_res cstd_mem_res;

typedef struct test {
	obj   head ;
	u64_t value;
}	test;

bool_t test_new	 (test* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")		    ; par_obj->value = va_arg(par, u64_t); return true_t; }
bool_t test_clone(test* par    , test* par_clone)			   { printf("Object Created As Clone\n"); return true_t; }
bool_t test_ref  (test* par)								   { printf("Object Referenced\n")	    ; return true_t; }
void   test_del  (test* par)								   { printf("Object Destroyed\n")	    ; }

obj_trait test_t		 = {
	.on_new	  = &test_new  ,
	.on_clone = &test_clone,
	.on_ref   = &test_ref  ,
	.on_del	  = &test_del  ,
	.size	  = sizeof(test)
};

int main() {
	mem_res_new(&cstd_mem_res, &cstd_mem_res_trait, 0);
	set_mem_res(&cstd_mem_res);

	list* list = make(list_t) from (0);

	for(u64_t i = 0 ; i < 3 ; ++i)
		list_push_front(list, make(&test_t) from(1, i));

	list_for(list, it)								{
		printf("%d\n", ((test*)list_get(it))->value);
		del   (list_get(it));
	}

	del(list);
}