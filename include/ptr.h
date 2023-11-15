#ifndef __PTR_H__
#define __PTR_H__

#include "type.h"
#include "type_atomic.h"

typedef struct ptr { u64_t ptr[2]; } ptr;

ptr    ptr_null()		   ;
ptr    ptr_seek(ptr, i64_t);
u64_t  ptr_dist(ptr, ptr)  ;
u64_t  ptr_cur (ptr)	   ;

void*  ptr_raw (ptr)	   ;
void*  ptr_mem (ptr)       ;
u64_t  ptr_size(ptr)       ;

bool_t ptr_rd8 (ptr, u8_t*)		  ;
bool_t ptr_rd16(ptr, u16_t*)	  ;
bool_t ptr_rd32(ptr, u32_t*)	  ;
bool_t ptr_rd64(ptr, u64_t*)	  ;
bool_t ptr_read(ptr, void*, u64_t);

bool_t ptr_wr8  (ptr, u8_t);
bool_t ptr_wr16 (ptr, u16_t);
bool_t ptr_wr32 (ptr, u32_t);
bool_t ptr_wr64 (ptr, u64_t);
bool_t ptr_write(ptr, void*, u64_t);

bool_t ptr_copy(ptr, ptr  , u64_t);
bool_t ptr_move(ptr, ptr  , u64_t);
bool_t ptr_eq  (ptr, void*, u64_t);
bool_t ptr_gt  (ptr, void*, u64_t);
bool_t ptr_lt  (ptr, void*, u64_t);

#ifndef __cplusplus
#define ptr_as(par_ptr, par_type) ((par_type)ptr_raw(par_ptr))
#endif

#endif