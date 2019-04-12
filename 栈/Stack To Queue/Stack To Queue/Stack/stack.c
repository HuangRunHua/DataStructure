//
//  stack.c
//  Stack To Queue
//
//  Created by Joker Hook on 2019/4/12.
//  Copyright © 2019 Joker Hook. All rights reserved.
//

#include "stack.h"

/**
 *@IBAction 创建一个空的栈
 */
stack *stack_creat()
{
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    if(NULL == s)
    {
        printf(__FUNCTION__);
        printf("ERROR in line %d\n",__LINE__);
        return (stack *) - 1;
    }
    bzero(s,sizeof(stack));
    s->top=-1;
    return s;
}

/**
 *@IBAction 清空栈
 */
void seqstack_clear(stack *s)
{
    s->top=-1;
}

/**
 *@IBAction 栈满
 */
datatype_t stack_full(stack *s)
{
    
    if(s->top >= N - 1)
    {
        printf("static full!\n");
        return (datatype_t)1;
    }
    else
        return (datatype_t)0;
}

/**
 *@IBAction 栈空
 */
datatype_t stack_empty(stack *s)
{
    if(s->top==-1)
    {
        printf("static empty!\n");
        return (datatype_t)1;
    }
    else
        return (datatype_t)0;
}

/**
 *@IBAction 入栈
 */
datatype_t stack_insert(stack *s,datatype_t value)
{
    if(stack_full(s))
        return (datatype_t) - 1;
    s->top++;
    s->data[s->top] = value;
    return (datatype_t)0;
}

/**
 *@IBAction 出栈
 */
datatype_t stack_out(stack *s)
{
    datatype_t value = s->data[s->top];
    if(stack_empty(s))
        return (datatype_t) - 1;
    s->top--;
    return value;
}

/**
 *@IBAction 打印栈数据
 */
datatype_t stack_show(stack *s)
{
    datatype_t i;
    if(stack_empty(s))
        return (datatype_t) - 1;
    for(i = 0;i <= s->top;i++)
        printf("top %d = %d.\n",i,s->data[i]);
    return (datatype_t)0;
}


