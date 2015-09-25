//
//  main.cpp
//  DFS
//
//  Created by Arena on 2015. 9. 24..
//  Copyright © 2015년 Arena. All rights reserved.
//

/// 이것은 그래프를 짜려고 이것저것 해본것이다.




#include <stdio.h>
#include <stdlib.h>

#include <stack>
#include <queue>
#include "stak.h"

int main(int argc, const char * argv[]) {
    
    poorGraph pG;
    
    int nodeSize, start;
    
    scanf("%d %d", &nodeSize, &start);
    
    pG.initGraphNode(nodeSize);
    
    int src, desc;
    
    for(int i = 0;true; i++){
        scanf("%d %d", &src, &desc);
        
        if(src != -1 && desc != -1){
            pG.addLink(src, desc);
        }else{
            printf("%d, iterated, break.\n", i);
            break;
        }

    }
    
    // 여기까지 기초 그래프 설정.
    
    // 해보자. traverse!!
    pG.doDFS(1);
    
    printf("yeah! done!\n");
    
    
    return 0;
}
