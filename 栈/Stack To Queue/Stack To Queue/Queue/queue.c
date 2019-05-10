//
//  queue.c
//  Stack To Queue
//
//  Created by Joker Hook on 2019/4/12.
//  Copyright © 2019 Joker Hook. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

/**
 *@IBAction 创建一个空栈队列
 */
queue *stackqueue_create()
{
    queue *sq = (queue *)malloc(sizeof(queue));
    sq->front = stack_creat();
    sq->real = stack_creat();
    if(NULL == sq)
    {
        printf(__FUNCTION__);
        printf("error in line %d.\n",__LINE__);
        return (queue*) - 1;
    }
    return sq;
}

/**
 *@IBAction 入队
 */
int push(queue *sq,int value)
{
    stack_insert(sq->real,value);
    return 0;
    
}

/**
 *@IBAction 出队
 */
datatype_t pop(queue *sq)
{
    if(!stack_empty(sq->real))
    {
        while(!stack_empty(sq->real))
        {
            stack_insert(sq->front,stack_out(sq->real));
        }
    }
    return stack_out(sq->front);
}

/**
 *@IBAction 打印队列
 */
void stackqueue_show(queue *sq)
{
    stack_show(sq->front);
    stack_show(sq->real);
}
