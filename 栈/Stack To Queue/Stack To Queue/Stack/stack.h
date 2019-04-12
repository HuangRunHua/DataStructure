//
//  stack.h
//  Stack To Queue
//
//  Created by Joker Hook on 2019/4/12.
//  Copyright © 2019 Joker Hook. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef int    datatype_t;                              // 为了后续修改队列里面的元素类型的方便
typedef struct {
    datatype_t data[N];                                 // 使用数组来实现栈
    datatype_t top;
} stack;

stack *stack_creat(void);                                // 创建一个空的栈
void stack_clear(stack_t *s);                            // 清空栈
datatype_t stack_full(stack *s);                         // 栈满
datatype_t stack_empty(stack *s);                        // 栈空
datatype_t stack_insert(stack *s,datatype_t value);      // 入栈
datatype_t stack_out(stack *s);                          // 出栈
datatype_t stack_show(stack *s);                         // 打印栈数据


#endif /* stack_h */
