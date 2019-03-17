//
//  list.c
//  链表合并习题
//
//  Created by Joker Hook on 2019/3/17.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"


/**
 * 初始化链表的代码
 */
List* init_List(List* list_first, List* list_previous, List* list_current)
{
    printf("Please Enter the number of List: ");
    int numberOfList_one = 0; // 链表里面的个数变量
    scanf("%d", &numberOfList_one);  // 让用户输入链表里面有多少个数字
    
    for (int i = 0; i<numberOfList_one; i++)
    {
        // 开始创建第一个链表
        list_current = (List*)malloc(sizeof(List));
        
        // 处理空链表的情况
        if (list_first == NULL)
        {
            list_first = list_current;
        }
        if (list_previous != NULL)
        {
            list_previous->next = list_current;
        }
        
        printf("Enter the number: ");  // 让用户输入填充的数字
        scanf("%d", &list_current->number);
        
        list_current->next = NULL;
        list_previous = list_current;
    }
    // printf("%d\n",list_first->number); // 测试使用接口
    return list_first;
}


/**
 * 打印出数字, 可作为测试使用的接口
 */
void print_List(List* list_first, List* list_previous, List* list_current) {
    while (list_current != NULL) {
        printf("%d\n",list_current->number);
        list_previous = list_current;
        list_current = list_current->next;
        free(list_previous);
        list_previous = NULL;
    }
    list_first = NULL;
    return;
}

/**
 * 输出排序以后链表里的数字
 */
void get_final_list(List *list1, List *list2, List *list3, List *list3_previous)
{
    List* La = (List*)malloc(sizeof(La));
    La->next = list1;
    
    List* Lb = (List*)malloc(sizeof(Lb));
    Lb->next = list2;
    
    List* Lc = (List*)malloc(sizeof(Lc));
    Lc->next = list3;

    Lc = sorted_List(La, Lb, Lc);
    
    print_List(list3, list3_previous, Lc->next);
}

/**
 * 最重要的排序算法
 */
List* sorted_List(List* La, List* Lb, List* Lc)
{
    List *pc = NULL;
    pc = La;
    Lc = La;
    
    List *pa = La->next;
    List *pb = Lb->next;
    
    while (pa && pb)
    {
        if (pa->number <= pb->number)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa: pb;
    free(Lb);
    
    return Lc;
}
