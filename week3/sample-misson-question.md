# 3주차 샘플미션에서 배운 것

## 컴파일이 CS50 IDE에선 되고, VSCODE에선 안 된다?
일단 샘플미션의 코드에 압도되지 않으려 노력하며, VSCODE에서 돌려보기 위해 코드를 복사해 붙여 넣었다. 그런데 컴파일이 되지 않았다. 엥? 전문가가 올려준 샘플미션의 코드가 컴파일부터 막히다니, 무언가 이상했다.
### 처음부터 시련! (VLA,가변크기배열선언, C99? 이게 다 뭐야?)
일단 문제가 됐던 코드 부분을 살펴보자.

```Java
const int NUMBER_OF_ANSWERS = 10;
const int ANSWERS[NUMBER_OF_ANSWERS] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

const int NUMBER_OF_GRADES = 9;
const int SCORES[NUMBER_OF_ANSWERS] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const char *GRADES[NUMBER_OF_ANSWERS] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};
```
위와 같은 코드를 돌리면 아래와 같은 오류 메시지가 배열 안의 인자 개수 만큼 주르르 펼쳐진다.

`error: variably modified 'ANSWERS' at file scope`
`warning: excess elements in array initializer`

배열 선언 시 인자가 초과됐다는 메시지, file scope ... variably modified ... ? 여튼 배열에 문제가 있었다.
그래서 바로 구글링을 해봤다. 몇 개의 블로그 글을 보고 빠르게 내린 결론은

> "VSCODE의 컴파일러가 C99(C언어의 최신 스펙)를 지원하지 않기 때문에 이 오류가 발생한 것"이다.

따라서 CS50 IDE는 C99를 지원하는 셈이다. 하지만 `const` 라는 뜻은 constant, 즉 '상수'라는 뜻이고 변하지 않는 다는 말인데, 왜 배열의 길이로 선언이 되지 않는 것일까?
