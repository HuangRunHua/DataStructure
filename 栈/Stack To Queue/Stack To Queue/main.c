//
//  main.c
//  Stack To Queue
//
//  Created by Joker Hook on 2019/4/12.
//  Copyright © 2019 Joker Hook. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue/queue.h"
#include "Stack/stack.h"

/*
  检验方式：
  完成队列的初始化、插入元素、删除元素这三个基本操作
 */

int main(int argc, const char * argv[]) {
    queue *p = stackqueue_create();
    push(p,1);
    push(p,2);
    push(p,3);
    pop(p);
    stackqueue_show(p);
    return 0;
}
