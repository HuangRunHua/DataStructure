//
//  clist.c
//  循环链表抽象数据类型的实现
//
//  Created by Joker Hook on 2019/3/7.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//
#include <stdlib.h>
#include <string.h>

#include "clist.h"

/**
 * clist_init
 */
void clist_init(CList *list, void (*destroy)(void *data))
{
    /* 初始化链表 */
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    
    return;
}

/**
 * clist_destroy
 */
void clist_destroy(CList *list)
{
    void *data;
    
    /* 删除每一个元素 */
    while (clist_size(list) > 0) {
        if (clist_rem_next(list, list->head, (void **)&data) == 0 && list->destroy != NULL)
        {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(CList));
    return;
}

/**
 * clist_ins_next
 */
int clist_ins_next(CList *list, CListElmt *element, const void *data)
{
    
    CListElmt *new_element;
    
    /* 分配空间 */
    if ((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL)
    {
        return -1;
    }
    
    /* 插入新元素 */
    new_element->data = (void *)data;
    
    if (clist_size(list) == 0)
    {
        /* 先解决链表为空的时候的插入问题 */
        new_element->next = element->next;
        list->head = new_element;
    } else {
        /* 解决基础情况 */
        new_element->next = element->next;
        element->next = new_element;
    }
    /* 调整链表大小 */
    list->size++;
    return 0;
}

/**
 * clist_rem_next
 */
int clist_rem_next(CList *list, CListElmt *element, void **data)
{
    CListElmt *old_element;
    
    /* 空链表时候无法删除 */
    if (clist_size(list) == 0)
    {
        return -1;
    }
    
    *data = element->next->data;
    if (element->next == element)
    {
        /* 删除最后一个元素 */
        old_element = element->next;
        list->head = NULL;
    } else {
        old_element = element->next;
        element->next = element->next->next;
        if (old_element == clist_head(list))
        {
            list->head = old_element->next;
        }
    }
    
    /* 释放内存 */
    free(old_element);
    
    /* 调整大小 */
    list->size--;
    
    return 0;
}
