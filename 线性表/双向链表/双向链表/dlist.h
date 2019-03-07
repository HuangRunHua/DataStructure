//
//  dlist.h
//  双向链表
//
//  Created by Joker Hook on 2019/3/5.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#ifndef dlist_h
#define dlist_h

/**
 * 双向链表由一个数据成员、一个指向下一个元素的next指针，以及一个指向前一个元素的prev指针组成
 * DListElmt代表双向链表中的元素
 * DList代表双向链表数据结构
 */
#include<stdlib.h>

/**
 * 定义一个双向链表的结构体元素
 */
typedef struct DListElmt_ {
    void *data;
    struct DListElmt_ *prev;
    struct DListElmt_ *next;
} DListElmt;

/**
 * 定义一个双向链表结构体
 */
typedef struct DList_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DlistElmt *tail;
} Dlist;

/**
 * 公共接口
 */
void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt *element, const void *data);
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);
int dlist_remove(DList *list, DListElmt *element, void **data);
#define dlist_size(list) ((list) -> size)

#define dlist_head(list) ((list) -> head)
#define dlist_tail(list) ((list) -> tail)
#define dlist_is_head(element) ((element) -> prev == NULL ? 1 : 0)
#define dlist_is_tail(element) ((element) -> next == NULL ? 1 : 0)
#define dlist_data(element) ((element) -> data)
#define dlist_next(element) ((element) -> next)
#define dlist_prev(element) ((element) -> prev)

#endif /* dlist_h */
