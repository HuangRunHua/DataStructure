//
//  Polynomial.h
//  多项式的乘法
//
//  Created by Joker Hook on 2019/3/23.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include <stdio.h>
#include <stdlib.h>
typedef struct Polynomial Polynomial;

/**
 * Polynomial 作为单个项来看代，它包含每一个项里面的系数、指数以及指向下一个项的指针
 */
struct Polynomial {
    float coef;            // 多项式的系数
    int exp;               // 多项式的指数
    Polynomial *next;      // 指向下一个结构体的指针
};

/**
 * 定义几个公共接口
 */

/* 允许用户自定义多项式 */
Polynomial* init_Polynomial(Polynomial* first_Polynomial, Polynomial* previous_Polynomial, Polynomial* current_Polynomial);

/* 打出用户自定义的多项式 */
void print_Polynomial(Polynomial* first_Polynomial, Polynomial* previous_Polynomial, Polynomial* current_Polynomial);

/* 多项式的插入 */
void Inset_Polynomial(Polynomial *polynomial, float coef, int exp);

/* 完成两个多项式的乘法 */
void multiplication_two_Polynomial(Polynomial* polynomial_one, Polynomial* polynomial_two, Polynomial* polynomial_three);

/* 输出相乘后的结果 */
void get_final_Polynomial(Polynomial* polynomial_one, Polynomial* polynomial_two, Polynomial* polynomial_three);


#endif /* Polynomial_h */
