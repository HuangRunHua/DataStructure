//
//  main.c
//  Stack To Queue
//
//  Created by Joker Hook on 2019/4/12.
//  Copyright © 2019 Joker Hook. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue/queue.h"
#include "Stack/stack.h"

int main(int argc, const char * argv[]) {
    queue *p = stackqueue_create();
    push(p,4);
    push(p,2);
    push(p,3);
    stackqueue_show(p);
    
    return 0;
}
