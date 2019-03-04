//
//  list.c
//  单链表
//
//  Created by Joker Hook on 2019/3/4.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/**
 * list_init 初始化链表
 *
 * 链表的size设置为0
 * destroy设置为定义的析构函数
 * head和tail指针设置为NULL
 *
 */
void list_init(List *list, void (*destroy)(void *data)) {
    /* 初始化链表 */
    list -> size = 0;
    list -> destroy = destroy;
    list -> head = NULL;
    list -> tail = NULL;
    
    return;
}

/**
 * list_destroy 销毁链表
 * 初始化时链表不为NULL，则当每一个元素被移除时都将调用list_destroy一次
 * list_destroy运行复杂度为O(n), n为链表g元素个数
 */
void list_destroy(List *list) {
    void *data;
    /* 删除每一个元素 */
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, &data) == 0 && list -> destroy != NULL) {
            /* 调用用户定义的函数来释放动态分配的数据 */
            list -> destroy(data);
        }
    }
    
    /* 现在不允许任何操作，但作为预防措施清除结构 */
    memset(list, 0, sizeof(List));
    return;
}

/* list_ins_next */
int list_ins_next(List *list, ListElmt *element, const void *data) {
    ListElmt *new_element;
    
    /* 分配内存给这个新元素 */
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL) {
        return -1;
    }
    
    /* 将元素插入到链表里面 */
    new_element -> data = (void *)data;
    if (element == NULL) {
        /* 处理列表头部的插入 */
        if (list_size(list) == 0) {
            list -> tail = new_element;
            new_element -> next = list -> head;
            list -> head = new_element;
        }
    } else {
        /* 处理除了头部的其他位置 */
        if (element -> next == NULL) {
            list -> tail = new_element;
        }
        new_element -> next = new_element -> next;
        element -> next = new_element;
    }
    
    /* 调整链表的大小 */
    list -> size++;
    
    return 0;
}


