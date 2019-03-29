//
//  stack.h
//  栈
//
//  Created by Joker Hook on 2019/3/29.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

/********************************************************************
 * 栈的实现方式有很多，在这里我使用链表来实现
 * 可以使用typedef Stack to List来实现，这样会使栈有多态的特性
 *
 * 我们举一个例子：
 * 假设要遍历一个栈里面的元素，通过这种方式来显示栈里面的元素或者判断元素是否属于栈
 * 为此，我们要获取list_head，然后用list_next遍历。
 * 在这里仅仅使用了栈的操作，一个一个取出压入临时的栈里面，最后再回去。
 ********************************************************************/


#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack,void **data);

#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

#endif /* stack_h */
