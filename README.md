# Algorithm
- 문제 해결 전략들을 주로 기술한다.
- 라이브러리 의존적으로 개발하는 습관에서 벗어나 스스로 모든 것을 만드는, 도구의 달인이 되어보자.

## Array based algorithms
- **배열 기반 선형 자료구조에서 사용하는 알고리즘**
- [Bubble Sort](https://github.com/csyouk/algorithm_datastructure/blob/master/Sorting-Algorithms/BubbleSort.md)
  - 거품이 물 위로 떠오르듯, 가장 큰 데이터를 정렬하고자 하는 데이터의 가장 뒷 편으로 밀어내는 기법.
- [Selection Sort](https://github.com/csyouk/algorithm_datastructure/blob/master/Sorting-Algorithms/SelectionSort.md)
  - 정렬하는 과정에서 가장 큰 데이터를 **선택** 해서 정렬하고자 하는 데이터의 가장 뒷 편으로 밀어내는 기법.
- [Insertion Sort](https://github.com/csyouk/algorithm_datastructure/blob/master/Sorting-Algorithms/InsertionSort.md)
  - 정렬과정에서 정렬해야 하는 데이터의 크기를 기준으로 데이터를 탐색하며 삽입할 위치를 찾아 **삽입** 하는 방법.
- [Quick Sort](https://github.com/csyouk/algorithm_datastructure/blob/master/Sorting-Algorithms/QuickSort.md)
  - 기준점(pivot)을 잡아서 기준점의 좌측(left)과 기준점을 지속적으로 비교하며 데이터의 크기가 있다면
  - 기준점(pivot)을 타겟(target)과 바꾸는 방법.
  - target을 기준점과 바꾼 후, pivot을 기준으로 좌측과 우측을 재귀적으로 quick sort를 시키는 방법.


## Graph based algorithms
- **그래프 기반 비선형 자료구조에서 사용하는 알고리즘**
- DFS(Depth Frist Search, 깊이 우선 탐색)
- BFS(Breadth Frist Search, 너비 우선 탐색)
- Dijkstra Algorithm(최단 거리 알고리즘)


# Data-Structure

## Linear
**Stored in Stack segment case**   
- [Array (homogeneous)](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Array.md)
- [Singly Linked List](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Stack-Segment/SinglyLinkedList.md)
- [Doubly Linked List](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Stack-Segment/DoublyLinkedList.md)
- [Stack](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Stack-Segment/Stack.md)
- [Queue](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Stack-Segment/Queue.md)

**Stored in Heap segment case**
- [Singly Linked List](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Heap-Segment/SinglyLinkedList.md)
- [Doubly Linked List](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Heap-Segment/DoublyLinkedList.md)
- [Stack](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Heap-Segment/Stack.md)
- [Queue](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/Linear/Heap-Segment/Queue.md)

## Non-Linear
- [Tree](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/None-Linear/HashTable.md)
- [Hash Table](https://github.com/csyouk/algorithm_datastructure/blob/master/Data-Structure/None-Linear/HashTable.md)
  - Open Addressing
  - Chaining Method
