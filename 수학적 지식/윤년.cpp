윤년의 기준
연도가 4의 배수이면서 100의 배수가 아닌 경우 또는 400의 배수인 경우

2012년은 4의 배수이면서 100의 배수가 아니므로 윤년
2000년은 400의 배수이기 때문에 윤년

즉 year%4==0 && year%100!=0 조건만 걸면 400의 배수가 안들어가니 조건 두개 걸어야 함
if( (year%400==0) || ((year%4==0)&&(year%100!=0)) )