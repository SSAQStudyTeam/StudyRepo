//  Header.h
//  DFS
//  Created by Arena on 2015. 9. 24..
//  Copyright © 2015년 Arena. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

#include <vector>
#include <stack>

class poorGraphNode{
public:
    int name;
    std::vector<int> link;
};

//양방향 그래프라고 해두자.
class poorGraph{
private:
    int size;
    std::vector<poorGraphNode *> nodes;
public:
    poorGraph(){
        size = 0;
    }
    void initGraphNode(int _size){
        size = _size;
        poorGraphNode * tmpNode;
        // 일단 Node 수 부터 배정.
        for(int i = 0; i<_size+1; i++){
            tmpNode = new poorGraphNode();
            tmpNode->name = i;
            nodes.push_back(tmpNode);
        }
        // 일단은 Node들만 넣어놨다.

    }
    void addLink(int src, int desc){
        //단방향 링크가 아니라 양방향 링크로 더하자.
        nodes[src]->link.push_back(desc);
        nodes[desc]->link.push_back(src);
    }
    
    
    // 알고리즘 플로우 차트는 아래와 같음.
    // 일단 현위치에서,
    // 다음 탐색할 자리가 있다? -> 현 위치를 그것으로 바꾸고 스택에 푸씨
    // 없다? -> 폽 하고 현 위치 변경.
    void doDFS(int start){
        std::vector<int> history;
        std::vector<int> now_location;
        
        history.push_back(start);
        now_location.push_back(start);
        int i = 0;
        
        while(now_location.size() != 0){
            // 현위치가 가지고 있는 링크의 값동안.
            while(i < nodes[now_location.back()]->link.size()){ //for (int i = 0; i < nodes[now_location.back()]->link.size();i++){
                //이미 탐색한 놈인지 먼저 검사해보자.
                //nodes[now_location]->link
                if(isTraversed(history, nodes[now_location.back()]->link[i]) == 0){
                    // 만약 Traversed한 이력이 없어!
                    // 다음 탐색 하러 가자.
                    printf("%d %d\n", now_location.back(), nodes[now_location.back()]->link[i]);
                    history.push_back(nodes[now_location.back()]->link[i]);
                    now_location.push_back(nodes[now_location.back()]->link[i]);
                    i = 0;
                    continue; //걸렸으니까 반복문 처음으로 돌아가자.(for문 용)
                }
                i++;
            } // 이걸 다 돌 동안 if에 안걸렸다는 건 곧 탐색할 놈이 없다는 것.
            i = 0;
            now_location.pop_back();
        }
        
        printf("traversal Completed.\n");
    }
    
    int isTraversed(std::vector<int>& history, int locale){
        for(int i = 0; i< history.size();i++){
            if(locale == history[i])
                return 1;
        }
        return 0;
    }

};
#endif /* Header_h */
