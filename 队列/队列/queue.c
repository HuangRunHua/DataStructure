//
//  queue.c
//  队列
//
//  Created by Joker Hook on 2019/3/29.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#include <stdlib.h>
#include "list.h"
#include "queue.h"

/* queue_enqueue */
int queue_enqueue(Queue *queue, const void *data) {
    /* 插入元素 */
    return list_ins_next(queue, list_tail(queue), data);
}

/* queue_dequeue */
int queue_dequeue(Queue *queue, void **data) {
    /* 删除头部元素 */
    return list_rem_next(queue, list_head(queue), data);
}

