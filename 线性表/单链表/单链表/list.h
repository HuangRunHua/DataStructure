//
//  list.h
//  链表抽象数据类型的头文件
//
//  Created by Joker Hook on 2019/3/4.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#ifndef list_h
#define list_h

#include<stdlib.h>

/**
 * Define a structure for linked list elements.
 */
typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

/**
 * Define a structure for linked lists.
 */
typedef struct List_ {
    int size; // 表示链表中元素的个数
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data); // 传递给list_init的析构函数
    ListElmt *head; // 指向链表头结点的指针
    ListElmt *tail; // 指向末尾结点的指针
} List;

/**
 * Public Interface
 */
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);
#define list_size(list) ((list) -> size)

#define list_head(list) ((list) -> head)
#define list_tail(list) ((list) -> tail)
#define list_is_head(list, element) ((element) == (list) -> head ? 1 : 0)
#define list_is_tail(element) ((element) -> next == NULL ? 1 : 0)
#define list_data(element) ((element) -> data)
#define list_next(element) ((element) -> next)


#endif /* list_h */
