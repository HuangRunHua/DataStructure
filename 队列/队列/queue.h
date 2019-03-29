//
//  queue.h
//  队列
//
//  Created by Joker Hook on 2019/3/29.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

/* 队列和栈一样，也用typedef Queue List 来定义它 */

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)
#define queue_size list_size

#endif /* queue_h */
