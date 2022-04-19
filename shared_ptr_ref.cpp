#include <iostream>
#include <memory>

int f(std::shared_ptr<int> ref)
{
    return ref.use_count();
}

int f2(std::shared_ptr<int>& ref)
{
    return ref.use_count();
}

int main()
{
    std::shared_ptr<int> temp = std::make_shared<int>(10);

    std::cout << temp.use_count() << '\n';
    // 해당 스코프를 벗어나면 shared_ptr이 자동으로 소멸된다
    {
        std::shared_ptr<int> temp2 = temp;
        std::cout << "temp : " << temp.use_count() << " temp2 : " << temp2.use_count() << '\n';
    }
    std::cout << temp.use_count() << '\n';
    std::cout << '\n' << "end scope shared_ptr" << '\n' << '\n';

    std::shared_ptr<int> s1 = std::make_shared<int>(10);
    std::cout << "s1 : " << s1.use_count() << '\n';
    std::cout << "f() : " << f(s1) << '\n';
    std::cout << "s1 : " << s1.use_count() << '\n';
    // 참조 호출 사용 x


    std::shared_ptr<int> s2 = std::make_shared<int>(10);
    std::cout << "s2 : " << s2.use_count() << '\n';
    std::cout << "f2() : " << f2(s2) << '\n';
    std::cout << "s2 : " << s2.use_count() << '\n';
    // 참조시 카운트 증가 하지 않음

    return 0;
}