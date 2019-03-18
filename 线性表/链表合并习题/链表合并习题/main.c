//
//  main.c
//  链表合并习题
//
//  Created by Joker Hook on 2019/3/17.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

/********************************************************
 注意事项：本题认为用户输入的数默认为由小到大排列。
 输入：  请输入链表集合里面元素的个数:  3      (用户指定第一个链表里元素的个数)
        请写下该链表的第1个元素:  1          (用户输入每一个数字)
        请写下该链表的第2个元素:  3
        请写下该链表的第3个元素:  5
        请输入链表集合里面元素的个数:  4      (用户指定第二个链表里元素的个数)
        请写下该链表的第1个元素:  2          (用户输入每一个数字)
        请写下该链表的第2个元素:  4
        请写下该链表的第3个元素:  6
        请写下该链表的第4个元素:  8
 
 输出：1 2 3 4 5 6 8    (按数字由小到大排列输出)
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, const char * argv[]) {
    
    /* 这是第一个链表的指针 */
    List *list_one_first = NULL;
    List *list_one_current = NULL;
    List *list_one_previous = NULL;
    
    /* 这是第二个链表的指针 */
    List *list_two_first = NULL;
    List *list_two_current = NULL;
    List *list_two_previous = NULL;
    
    /* 调用公共接口，初始化两个基础链表 */
    list_one_first = init_List(list_one_first, list_one_previous, list_one_current);
    list_two_first = init_List(list_two_first, list_two_previous, list_two_current);
    
    printf("\n");
    list_one_current = list_one_first;
    list_two_current = list_two_first;

    
    /**
     * 我们需要第三个链表来作为代理，方便我们操作代码
     */
    List *list_three_first = NULL;
    List *list_three_previous = NULL;
    
    /* 在函数内部合并、排序，最后输出结果 */
    get_final_list(list_one_first, list_two_first, list_three_first, list_three_previous);
    
    return 0;
}
