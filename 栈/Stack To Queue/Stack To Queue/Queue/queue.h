//
//  queue.h
//  Stack To Queue
//
//  Created by Joker Hook on 2019/4/12.
//  Copyright © 2019 Joker Hook. All rights reserved.
//

/*
  现在设有俩个栈s1，s2。
  完成一个队列入队时，数据进入栈s1。出队时检查s2栈是否为空，为空则将s1出栈，出栈数据依次入栈s2。
  完成一个s1全部出栈后，s2出栈既是此时的出队操作。
  如果s2不为空，那s2直接出栈。如果s2，s1都为空，此时队列为空，无法执行出队操作
 */

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct stackqueue_p{
    stack *front;
    stack *real;
    int count;
} queue;

queue *stackqueue_create(void);         // 创建队列
int push(queue *q,int value);           // 插入元素
datatype_t pop(queue *q);               // 删除元素
void stackqueue_show(queue *q);         // 打印出元素

#endif /* queue_h */
