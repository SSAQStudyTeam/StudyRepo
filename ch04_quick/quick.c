#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 1회 전체 실행하는 함수를 하나.
// 하위에 재귀적으로 호출되는 함수를 하나 더.

int sub_quick(int *array, int left, int right);
int quick(int *array);

int quick(int *array){

  // 여기서는 이니셜 호출만을 담당하고, 나머지는 아래에서 알아서 하자.
  // 인덱스 포인트들.
  // 아래를 통해 호출을 하자.
  sub_quick(array, 0, 19);
  

  return 0;
}

int sub_quick(int *array, int left, int right){

  // 종료 컨디션을 세팅한다.
  int _left, _right, _pivot;
  int temp;

  _pivot = right;
  _right = right-1;
  _left  = left;

  while(_left < _right){

    while(array[_left] < array[_pivot] && _left < _right)  _left++;
    while(array[_right] > array[_pivot] && _left < _right) _right++;

    // 좌우 스왑 실시..
    temp = array[_left];
    array[_left] = array[_right];
    array[_right] = temp;

  }
  // 반복문을 종료했으므로, 좌우 대통합을 이룬 상태.
  // 고로 피벗과 교환하자.
  temp = array[_pivot];
  array[_pivot] = array[_right];
  array[_right] = temp;

  _pivot = _left;

  // 만약 좌와 우가 만나면, 피벗과 위치를 교환하고 재귀 호출을 하자.
  if (left < _pivot)
    sub_quick(array, left, _left-1);
  if (right > _pivot)
    sub_quick(array, _left+1, right);

  return 0;
}

int main(){

  // 정렬할 녀석을 배열로 잡자.
  int before_sort[20];

  srand(time(NULL));

  for(int i = 0; i<20; i++){
    before_sort[i]= rand() % 450;
    printf("%d  ", before_sort[i]);
  }

  quick(before_sort);

  printf("\n after sorted : \n");

  for(int i = 0; i<20; i++){
    printf("%d  ", before_sort[i]);
  }

  printf("Hello, fuckin` world!\n");
  return 0;
}