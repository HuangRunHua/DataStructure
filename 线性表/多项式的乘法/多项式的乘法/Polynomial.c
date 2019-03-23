//
//  Polynomial.c
//  多项式的乘法
//
//  Created by Joker Hook on 2019/3/23.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Polynomial.h"

/**
 * 初始化我们的多项式，用户需要给出每一个多项式的项数、每一项的系数和指数。
 */
Polynomial* init_Polynomial(Polynomial* first_Polynomial, Polynomial* previous_Polynomial, Polynomial* current_Polynomial) {
    
    int lengthOfPolynomialOne = 0;
    printf("给出多项式的项数：");
    scanf("%d", &lengthOfPolynomialOne);  // 用户输入多项式的长度
    
    /* 用户开始输入每一个项的系数和指数 */
    for (int i = 1; lengthOfPolynomialOne > 0; i++,lengthOfPolynomialOne--) {
        
        current_Polynomial = (Polynomial*)malloc(sizeof(Polynomial));
        
        if (first_Polynomial == NULL) {
            first_Polynomial = current_Polynomial;
        }
        if (previous_Polynomial != NULL) {
            previous_Polynomial->next = current_Polynomial;
        }
        
        printf("请给出第 %d 个项的系数：",i);
        scanf("%f",&current_Polynomial->coef);
        printf("请给出第 %d 个项的指数：",i);
        scanf("%d",&current_Polynomial->exp);
        current_Polynomial->next = NULL;
        previous_Polynomial = current_Polynomial;
    }
    return first_Polynomial;
}

/**
 * 打印出用户自定义的多项式
 * 指数高的项在前，指数低的项在后
 */
void print_Polynomial(Polynomial* first_Polynomial, Polynomial* previous_Polynomial, Polynomial*   current_Polynomial) {
    printf("多项式相乘以后的结果为 f(x) = ");
    
    while (current_Polynomial != NULL) {
        
        /* 当项的系数为正的时候，要出现+号 */
        if (current_Polynomial->coef >= 0) {
            printf("+%fx^%d",current_Polynomial->coef,current_Polynomial->exp);
        }
        
        /* 为了不打印出系数为0的项，就没有讨论项系数为0的情况 */
        if (current_Polynomial->coef < 0) {
            printf("%fx^%d",current_Polynomial->coef,current_Polynomial->exp);
        }
        
        previous_Polynomial = current_Polynomial;
        current_Polynomial = current_Polynomial->next;
        free(previous_Polynomial);
        previous_Polynomial = NULL;
    }
    printf("\n");
    first_Polynomial = NULL;
    return;
}


/**
 * 完成多项式的插入，其实现的功能为：
 * 如果多项式里面没有与新的项的指数相等的项，就将这个新的项插入到链表合适的位置；如果有相同的指数的项，就将两个项合并
 */
void Inset_Polynomial(Polynomial *polynomial, float coef, int exp) {
    Polynomial *pre = polynomial;
    Polynomial *p = polynomial->next;
    while (p!=NULL && p->exp>exp) {
        pre = p;
        p = p->next;
    }
    if (p->exp == exp) {                                    // 多项式中有与新项指数相同的项的处理
        if (p->coef+coef != 0) {
            p->coef = p->coef+coef;                         // 当系数相加不为0合并指数相同的项
        } else {
            pre->next = p->next;                            // 当系数相加为0时删除每一项
            free(p);
        }
    } else {                                                // 处理指数不相同的情况
        Polynomial* pc = (Polynomial*)malloc(sizeof(pc));   // 开辟一个新的项，并将其添加到现有的多项式里
        pc->exp = exp;
        pc->coef = coef;
        pre->next = pc;
        pc->next = p;
    }
    return;
}


/**
 * 按照推导的公式完成多项式的乘法
 */
void multiplication_two_Polynomial(Polynomial* polynomial_one, Polynomial* polynomial_two, Polynomial* polynomial_three) {
    Polynomial *pa, *pb;
    pa = polynomial_one->next;
    while (pa != NULL) {
        pb = polynomial_two->next;
        while (pb != NULL) {
            Inset_Polynomial(polynomial_three, pa->coef*pb->coef, pa->exp+pb->exp);
            pb = pb->next;
        }
        pa = pa->next;
    }
    Polynomial* polynomial_three_previous = (Polynomial*)malloc(sizeof(polynomial_three_previous));
    polynomial_three_previous = NULL;
    print_Polynomial(polynomial_three, polynomial_three_previous, polynomial_three->next);
    
    return;
}

/**
 * 输出相乘后的结果
 */
void get_final_Polynomial(Polynomial* polynomial_one, Polynomial* polynomial_two, Polynomial* polynomial_three) {
    
    Polynomial* pa = (Polynomial*)malloc(sizeof(pa));       // 创建 polynomial_one 的头结点
    pa->next = polynomial_one;
    
    Polynomial* pb = (Polynomial*)malloc(sizeof(pb));       // 创建 polynomial_two 的头结点
    pb->next = polynomial_two;
    
    Polynomial* pc = (Polynomial*)malloc(sizeof(pc));       // 创建 polynomial_three 的头结点
    pc->next = polynomial_three;
    pc->next->next = NULL;
    
    multiplication_two_Polynomial(pa, pb, pc);              // 两个多项式相乘并输出
    
    return;
    
}
