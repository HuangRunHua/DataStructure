//
//  main.c
//  LinkListExercises
//
//  Created by Joker Hook on 2019/3/17.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

/**
 * 已知两个非降序的链表序列, 请构造出它们合并后的非降序链表.
 * 采用一个单链表的方法，将 M1 里的每一个数字插入到 M2 里
 *
 * 输入：两个链表的值
 * 输出：比较后的链表
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"



int main(int argc, const char * argv[])
{
    
    // - Note： 这是第一个链表的指针
    List *list_one_first = NULL;
    List *list_one_current = NULL;
    List *list_one_previous = NULL;
    
    // - Note: 这是第二个链表的指针
    List *list_two_first = NULL;
    List *list_two_current = NULL;
    List *list_two_previous = NULL;
    
    printf("Please Enter the number of List: ");
    int numberOfList_one = 0; // 第一个链表里面有多少个数字变量
    scanf("%d", &numberOfList_one);  // 让用户输入第一个链表里面有多少个数字
    
    for (int i = 0; i<numberOfList_one; i++) {
        // 开始创建第一个链表
        list_one_current = (List*)malloc(sizeof(List));
        
        // 处理空链表的情况
        if (list_one_first == NULL) {
            list_one_first = list_one_current;
        }
        if (list_one_previous != NULL) {
            list_one_previous->next = list_one_current;
        }
        
        printf("Enter the number: ");
        scanf("%d", &list_one_current->number);
        
        list_one_current->next = NULL;
        list_one_previous = list_one_current;
    }
    
    
    // - Mark: 这是第二个链表的初始化
    printf("Please Enter the number of List: ");
    int numberOfList_two = 0; // 第一个链表里面有多少个数字变量
    scanf("%d", &numberOfList_two);  // 让用户输入第一个链表里面有多少个数字
    
    for (int i = 0; i<numberOfList_two; i++) {
        // 开始创建第一个链表
        list_two_current = (List*)malloc(sizeof(List));
        
        // 处理空链表的情况
        if (list_two_first == NULL) {
            list_two_first = list_two_current;
        }
        if (list_two_previous != NULL) {
            list_two_previous->next = list_two_current;
        }
        
        printf("Enter the number: ");
        scanf("%d", &list_two_current->number);
        
        list_two_current->next = NULL;
        list_two_previous = list_two_current;
    }

    
    /**
     * 此处进行排序工作
     * 我们需要第三个链表来作为代理，方便我们操作代码
     */
    List *list_three_first = NULL;
    List *list_three_current = NULL;
    List *list_three_previous = NULL;
    
    /**
     * 在这里，我给每一个链表又添加了一个指向链表头的指针 La、Lb、Lc
     */
    List *La = (List*)malloc(sizeof(La));
    La->next = list_one_first;
    
    List *Lb = (List*)malloc(sizeof(Lb));
    Lb->next = list_two_first;
    
    List *Lc = (List*)malloc(sizeof(Lc));
    Lc->next = list_three_first;
    
    
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
    
    
    
    /**
     * 展示我们的链表
     */
    
    list_three_current = Lc->next;
    while (list_three_current != NULL)
    {
        printf("%d\n",list_three_current->number);
        list_three_previous = list_three_current;
        list_three_current = list_three_current->next;
        free(list_three_previous);
        list_three_previous = NULL;
    }
    list_three_first = NULL;

    return 0;
}
