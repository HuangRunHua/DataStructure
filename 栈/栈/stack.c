//
//  stack.c
//  栈
//
//  Created by Joker Hook on 2019/3/29.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#include <stdlib.h>

#include "list.h"
#include "stack.h"

/* stack_push */
int stack_push(Stack *stack, const void *data) {
    /* 将元素推入栈里面 */
    return list_ins_next(stack, NULL, data);
}

/* stack_pop */
int stack_pop(Stack *stack, void **data) {
    /*  将最后一个元素推出栈 */
    return list_rem_next(stack, NULL, data);
}
