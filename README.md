# ConstantNodeMultiIterationTest

2회 이상의 linked list를 순회할 때, loop 분기 명령을 쓰는 횟수를 절약해 보면 어떨까?

...라는 발상으로 만들어진, 나비 모양(...)의 코드.

성능 테스트를 해봤습니다.

#테스트 시나리오
1. linked list를 평벙한 방식으로 끝까지 순회하기.
1. listed list를 10개마다 나비모양 코드로 분기명령 없이 순회하기.

CPU가 얼마나 스마트하게 처리하는지를 보기 위해, 컴파일러 최적화 끔. 당연히 릴리즈 모드.

#테스트 결과
후자가 약 1.5배정도 빠름.

#테스트 결과에 대한 생각
분기명령을 줄이는 것이 효과적이긴 하지만, 그래도 cache miss가 일어나는 메모리 액세스에 비할 바가 아니다.

#기타사항

대충 짠 코드이고, 정확한 결과라고 바로 장담 못합니다.

집단지성으로 정확화 기대해봅니다.
