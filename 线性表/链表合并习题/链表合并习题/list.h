//
//  list.h
//  链表合并习题
//
//  Created by Joker Hook on 2019/3/17.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>

/* 使用 typedef 进行简写 */
typedef struct List List;

/**
 * 创建了一个 List 的结构体
 * 这是一个单链表，功能比较简单
 */
struct List
{
    int number;  // 储存一个数字
    List *next;  // 指向下一个List的指针
};

/**
 * 开放的公共接口
 */
List* init_List(List* list_first, List* list_previous, List* list_current);  // 允许用户自定义链表
void print_List(List* list_first, List* list_previous, List* list_current); // 打印出链表里的数字
void get_final_list(List *list1, List *list2, List *list3, List *list3_previous);  // 直接输出合并、排序后的链表
List* sorted_List(List* La, List* Lb, List* Lc);  // 对传入的两个链表进行合并和排序，返回合并以后链表的头指针

#endif /* list_h */
