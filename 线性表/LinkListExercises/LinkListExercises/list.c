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
 * 初始化链表
 */
void init_List(List* list_first, List* list_previous, List* list_current) {
    printf("Please Enter the number of List: ");
    int numberOfList_one = 0; // 第一个链表里面有多少个数字变量
    scanf("%d", &numberOfList_one);  // 让用户输入第一个链表里面有多少个数字
    
    for (int i = 0; i<numberOfList_one; i++) {
        // 开始创建第一个链表
        list_current = (List*)malloc(sizeof(List));
        
        // 处理空链表的情况
        if (list_first == NULL) {
            list_first = list_current;
        }
        if (list_previous != NULL) {
            list_previous->next = list_current;
        }
        
        printf("Enter the number: ");
        scanf("%d", &list_current->number);
        
        list_current->next = NULL;
        list_previous = list_current;
    }
}


/**
 * 打印出数字
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
}

