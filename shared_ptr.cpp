#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <queue>

// shared_ptr  스마트 포인터 클래스
// 포인터를 더 이상 사용 하지 않으면 메모리 자동으로 해재해줌
// 메모리를 제때 해재 안해 발생하는 메모리 릭을 방지해줌
class CInvoker{
	public:
		CInvoker(){}
		virtual ~CInvoker(){}
		bool getCheckValue(){ return m_checkValue; }
	private:
		std::vector<int>m_insprite;
		int32_t m_count;
		int32_t m_size;
		int64_t m_longSize;
		bool m_checkValue;
};

int main()
{
    // 객체 생성 후 바로 메모리 포인터 연결
    std::shared_ptr<int> s1(new int(10));
    std::shared_ptr<int> s2 = std::make_shared<int>(10); // make_shared 권장
    std::shared_ptr<std::string> s3 = std::make_shared<std::string>("it's me");
    
    //std::shared_ptr<int> temp = new int() 에러 발생  shared_ptr의 생성자는 명시적이여야함
    std::shared_ptr<int> temp = std::make_shared<int>();

    // use_count() 함수를 사용해 shared_ptr 객체에 참조하는 카운트를 알 수 있음
    // make_shared  default 참조 카운트 1
    // nullptr 을 대입시 참조 카운트가 0이되며 다른 변수는 카운트 1 감소
    // reset() 사용시 참조 카운트 0이됨  -->  shared_ptr이 가리키는 메모리가 없는 상태 --> delete를 사용하여 메모리를 해재(자동)
    
    std::cout << *s1 << '\n';
    std::cout << *s2 << '\n';
    std::cout << *s3 << '\n';

    std::cout << '\n';
    std::cout << "Use Count" << '\n';
    std::cout << '\n';
    
    std::shared_ptr<int> s;
    std::cout << s.use_count() << '\n';  // 0예상

    s = std::make_shared<int>(10);
    std::cout << s.use_count() << '\n';  // 1예상

    std::shared_ptr<int> s4;
    s4 = s;
    std::cout << "s : " << s.use_count() << " s2 : " << s4.use_count() << '\n';

    s = nullptr;
    std::cout << "s : " << s.use_count() << " s2 : " << s4.use_count() << '\n';

    s = s4;
    std::cout << "s : " << s.use_count() << " s2 : " << s4.use_count() << '\n';

    s.reset();
    std::cout << "s : " << s.use_count() << " s2 : " << s4.use_count() << '\n';
    s4.reset();
    std::cout << "s : " << s.use_count() << " s2 : " << s4.use_count() << '\n';
    CInvoker* cinvoker = new CInvoker();
    std::cout << "here CInvoker -> " << static_cast<int>(cinvoker->getCheckValue()) << " ##\n";
    return 0;
}
