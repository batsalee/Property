# 1. deque의 개념
양쪽에서 끝나는 큐 (Double ended queue)
[데크]라고 발음

보통 stack의 경우 top에서 pop과 push가 일어나고 반대쪽에서는 아무것도 할 수 없다. 
또한 queue의 경우 한쪽에서는 삭제, 반대쪽에서는 삽입이 일어나지만, 삭제하는 쪽에서는 삽입을, 반대쪽에서는 삭제를 할 수 없다.
하지만 deque의 경우 스택과 큐를 합친 것이라 볼 수 있으며, 양쪽 끝에서 삭제와 입력 모두 수행할 수 있게 된다.

vector는 사전에 할당한 공간이 꽉 찼을 경우 새로 큰 메모리를 할당해서 기존의 값들을 옮기고 새로 추가된 값을 이어 붙여줌
하지만 deque는 메모리상에서 잘게 쪼개서 보관하고, 테이블에 각 조각의 위치를 기억함, 그래서 vector에서 발생하는 비효율이 deque에서는 발생하지 않음

메모리의 작은 block들을 효율적으로 사용할 수 있게 됨
물론 테이블때문에 메모리 공간을 더 사용하게 될 수도 있음

다른 순차 컨테이너처럼 deque에서도 데이터는 선형으로 메모리 상에 위치하게 된다.
데크는 원소에 iterator를 통해 접근할 수 있고, 크기 할당은 자동으로 수행한다.
처음과 끝 말고 중간에 원소의 삽입과 삭제를 빈번하게 사용한다면 데크 보다는 리스트(list)를 사용하는 것을 추천한다.
  
  
# 2. deque의 장점
1) 인덱스 값을 통해 접근할 수 있다.
2) itorater로 원소를 어떠한 방향으로도 참조해 나갈 수 있다.
3) 데크 시작과 끝에 원소의 추가/삭제가 효율적이다.


# 3. deque의 단점
1) 모든 원소가 메모리 상에 연속적으로 존재한다고 보장할 수 없다. 즉, 포인터 연산을 통해서 데크의 원소들을 안전하게 접근할 수 없다.


# 4. deque의 멤버 변수들

- reference : Allocator::reference
- const_reference : Allocator::const_reference

- iterator : 임의 접근 반복자(random access iterator)
- const_iterator : 상수 임의 접근 반복자 (즉, 접근하는 원소의 내용을 수정 못함)
- reverse_iterator : 역 반복자 (끝에서 부터 참조해나간다) reverse_iterator<iterator>
- const_reverse_iterator : 상수 역 반복자 (reverse_iterator<const_iterator>)

- size_type : 데크 size 를 나타내는 타입 (많은 경우 size_t 와 타입이 같으며 부호없는 정수이다)

- difference_type : 데크 내의 두 원소 사이의 거리를 나타내는 타입 (많은 경우 ptfdiff_t 와 타입이 같으며 부호있는 정수)

- value_type : 원소 타입 (T)

- allocator_type : 할당자

- pointer : 포인터 (Allocator::pointer)
- const_pointer : 상수 포인터 (Allocator::const_pointer)

  
# 5. deque의 멤버 함수들
1) 생성자 : 데크를 생성한다.
2) 소멸자 : 데크를 소멸한다.
3) 연산자
  - operator= : 데크의 내용을 복사한다.
  - operator[] : 원소에 접근한다.(임의 접근)

4) 반복자
  - begin : 시작 부분 (첫번째 원소) 을 가리키는 반복자를 리턴한다.
  - end : 끝 부분 (마지막 원소 바로 다음) 을 가리키는 반복자를 리턴한다.
  - rbegin : 역순으로 첫번째 (즉, 마지막 원소) 를 가리키는 반복자를 리턴한다.
  - rend : 역순으로 끝 부분 (즉, 첫번째 원소 바로 이전) 을 가리키는 반복자를 리턴한다.

5) 할당 관련
  - 벡터와는 다르게 capacity 와 reserve 가 없다!
  - size : 데크의 size 를 리턴한다 (현재 원소의 개수)
  - max_size : 데크 최대 크기를 리턴한다.
  - resize : 데크가 size 개의 원소를 포함하도록 변경한다.
  - empty : 데크가 비었는지 체크한다.

6) 접근자
  - at : 원소에 접근한다.
  - front : 첫번째 원소에 접근한다.
  - back : 마지막 원소에 접근한다.

7) 수정자 (Modifier)
  - assign : 데크에 원소를 집어넣는다.
  
  - push_back : 데크 끝에 원소를 집어 넣는다.
  - push_front : 데크 맨 앞에 원소를 집어 넣는다.
  - pop_back : 마지막 원소를 제거한다.
  - pop_front : 첫번째 원소를 제거한다.

  - insert : 데크 중간에 원소를 추가한다.

  - erase : 원소를 제거한다.
  - swap : 다른 데크와 원소를 바꿔치기 한다.
  - clear : 원소를 모두 제거한다.

8) 할당자
  - get_allocator : 할당자(allocator) 을 얻는다.
