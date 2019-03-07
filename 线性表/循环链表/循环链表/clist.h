//
//  clist.h
//  循环链表
//
//  Created by Joker Hook on 2019/3/7.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#ifndef clist_h
#define clist_h

#include <stdio.h>
#include <stdlib.h>

/**
 * 定义一个循环链表元素的结构体
 */
typedef struct CListElmt_
{
    void *data;
    struct CListElmt_ *next;
} CListElmt;

/**
 * 定义一个循环链表结构体
 */
typedef struct CList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy) (void *data);
    CListElmt *head;
} CList;

/**
 * 公共接口
 */
void clist_init(CList *list, void (*destroy)(void *data));
void clist_destroy(CList *list);
int clist_ins_next(CList *list, CListElmt *element, const void *data);
int clist_rem_next(CList *list, CListElmt *element, void **data);
#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)

#endif /* clist_h */
