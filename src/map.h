#ifndef __MAP_H__
#define __MAP_H__

#include "obj.h"
#include "list.h"

typedef struct map_key       {
    bool_t (*eq)(obj*, void*);
    bool_t (*lt)(obj*, void*);
    bool_t (*gt)(obj*, void*);
}   map_key;

extern obj_trait* map_t   ;
typedef struct    map     {
    obj      head;
    map_key* key ;
    list     map ;
}   map;

bool_t map_new  (map*, u32_t, va_list);
bool_t map_clone(map*, map*)          ;
void   map_del  (map*)                ;

node*  map_push (map*, obj*)          ;
void   map_pop  (map*, obj*)          ;
node*  map_find (map*, obj*)          ;

bool_t map_empty(map*)                ;
node*  map_begin(map*)                ;
node*  map_end  (map*)                ;

#endif