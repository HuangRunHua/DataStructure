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


/**
 * list_ins_next
 * 将一个元素插入到由element参数所指定的元素后面
 */
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

/**
 * list_rem_next
 * 移除由element所指定的元素后面的那个结点
 */
int list_rem_next(List *list, ListElmt *element, void **data) {
    ListElmt *old_element;
    /* 空的链表不操作 */
    if (list_size(list) == 0) {
        return -1;
    }
    
    /* 非空链表的移除操作 */
    if (element == NULL) {
        /* 解决头部结点的问题 */
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;
        
        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        /* 解决其余地方 */
        if (element->next == NULL) {
            return -1;
        }
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        
        if (element->next == NULL) {
            list->tail = element;
        }
    }
    
    /* 释放抽象数据类型分配的存储空间 */
    free(old_element);
    
    /* 调整链表大小 */
    list->size--;
    return 0;
}

