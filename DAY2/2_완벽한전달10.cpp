// forwarding reference(T&&) 가 사용되는 대표적인 경우

// 1. 완벽한 전달 기술 : chronometry 예제
//    => 인자로 전달받은 것은 다른 함수로 완벽히 전달하기 위해

// 2. move를 지원하는 setter(생성자)를 만들때 사용
//	  => People 예제


// move 지원 setter(생성자 만들기)
// 
// 1. 인자가 한개라면 "2개의 함수"를 만드세요
// 2. 인자가 2개 이상이면 "forwarding reference" 기술을 사용하세요