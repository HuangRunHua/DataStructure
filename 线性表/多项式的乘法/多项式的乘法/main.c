//
//  main.c
//  多项式的乘法
//
//  Created by Joker Hook on 2019/3/23.
//  Copyright © 2019 com.icloud@h76joker. All rights reserved.
//

/**********************************************************
 注意事项：此算法假定多项式的指数只能为整数且都大于或等于0
 输入：   给出多项式的项数：1
         请给出第 1 个项的系数：3
         请给出第 1 个项的指数：1     (f(x) = 3x)
         给出多项式的项数：2
         请给出第 1 个项的系数：4
         请给出第 1 个项的指数：1
         请给出第 2 个项的系数：-1
         请给出第 2 个项的指数：0     (f(x) = 4x - 1)
 
 输出：   多项式相乘以后的结果为 f(x) = +12.000000x^2-3.000000x^1+0.000000x^0
 ***********************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

int main(int argc, const char * argv[]) {

    /* 我们先创建第一个多项式的指针 */
    Polynomial *first_Polynomial_one = NULL;
    Polynomial *current_Polynomial_one = NULL;
    Polynomial *previous_Polynomial_one = NULL;
    
    /* 我们创建第二个多项式的指针 */
    Polynomial *first_Polynomial_two = NULL;
    Polynomial *current_Polynomial_two = NULL;
    Polynomial *previous_Polynomial_two = NULL;
    
    /* 初始化第一个多项式 */
    first_Polynomial_one = init_Polynomial(first_Polynomial_one, previous_Polynomial_one, current_Polynomial_one);
    
    /* 初始化第二个多项式 */
    first_Polynomial_two = init_Polynomial(first_Polynomial_two, previous_Polynomial_two, current_Polynomial_two);
    
    Polynomial* polynomial_three = (Polynomial*)malloc(sizeof(polynomial_three));
    
    /* 核心程序 */
    get_final_Polynomial(first_Polynomial_one, first_Polynomial_two,polynomial_three);
    
    return 0;
}
