//
//  dlist.c
//  双向链表抽象数据类型的实现
//
//  Created by Joker Hook on 2019/3/5.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/**
 * dlist_init
 */
void dlist_init(DList *list,void (*destroy)(void *data))
{
    /* 初始化双向链表 */
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}

/**
 * dlist_destroy
 */
void dilst_destroy(DList *list)
{
    void *data;
    
    /*  删除每一个元素 */
    while (dlist_size(list) > 0)
    {
        if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->destroy != NULL)
        {
            list->destroy(data);
        }
    }
    
    /* 现在不允许任何操作，但作为预防措施清除结构 */
    memset(list, 0, sizeof(DList));
    return;
}

/**
 * dlist_ins_next
 */
int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
    
    DListElmt *new_element;
    
    /* 除非列表为空，否则不允许NULL元素 */
    if (element == NULL && dlist_size(list) != 0)
    {
        return -1;
    }
    
    /* 分配空间 */
    if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
    {
        return -1;
    }
    
    /* 插入新元素 */
    new_element->data = (void *)data;
    
    if (dlist_size(list) == 0)
    {
        /* 先解决链表为空的时候的插入问题 */
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    } else {
        /* 解决基础情况 */
        new_element->next = element->next;
        new_element->prev = element;
        if (element->next == NULL)
        {
            list->tail = new_element;
        } else {
            element->next->prev = new_element;
        }
        element->next = new_element;
    }
    /* 调整链表大小 */
    list->size++;
    return 0;
}

/**
 * list_ins_prev
 */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data)
{
    
    DListElmt *new_element;
    
    /* 除非列表为空，否则不允许NULL元素 */
    if (element == NULL && dlist_size(list) != 0)
    {
        return -1;
    }
    
    /* 分配空间 */
    if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
    {
        return -1;
    }
    
    /* 插入新元素 */
    new_element->data = (void *)data;
    
    if (dlist_size(list) == 0)
    {
        /* 先解决链表为空的时候的插入问题 */
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    } else {
        /* 解决基础情况 */
        new_element->next = element;
        new_element->prev = element->prev;
        if (element->prev == NULL)
        {
            list->head = new_element;
        } else
        {
            element->prev->next = new_element;
        }
        element->prev = new_element;
    }
    /* 调整链表大小 */
    list->size++;
    return 0;
}

/**
 * dlist_remove
 */
int dlist_remove(DList *list, DListElmt *element, void **data)
{
    
    /* 不能传入空元素以及空链表b无法删除 */
    if (element == NULL || dlist_size(list) == 0)
    {
        return -1;
    }
    
    /* 删除元素 */
    *data = element->data;
    
    if (element == list->head)
    {
        /* 删除开头 */
        list->head = element->next;
        
        if (list->head == NULL)
        {
            list->tail = NULL;
        } else {
            element->next->prev = NULL;
        }
    } else {
        /* 解决一般情况 */
        element->prev->next = element->next;
        if (element->next == NULL)
        {
            list->tail = element->prev;
        } else {
            element->next->prev = element->prev;
        }
    }
    /* 释放空间 */
    free(element);
    
    /* 调整大小 */
    list->size--;
    
    return 0;
}
