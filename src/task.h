#ifndef __TASK_H__
#define __TASK_H__

#include "obj.h"

extern struct obj_trait* task_t;
typedef struct			 task { u8_t task[512]; } task;

#endif