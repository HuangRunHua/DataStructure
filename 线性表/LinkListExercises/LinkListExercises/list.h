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

// - Note: 创建了一个 List 的结构体
typedef struct List List;

struct List
{
    int number;
    List *next;
};

void init_List(List* list_first, List* list_previous, List* list_current); // 初始化链表
void print_List(List* list_first, List* list_previous, List* list_current); // 打印出数字


#endif /* list_h */
