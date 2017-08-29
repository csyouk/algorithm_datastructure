# Recursive Function


```cpp
void recursive()
{
  static int cnt = 0;
  // 시작하자 마자 종료조건을 기입한다.
  if(cnt == 10) return ;

  /*
  * 본체에 해당하는 구현부분을 이곳에 작성한다.
  * /
  recursive(); // 라이브러리 함수처럼 호출한다.
}
```
