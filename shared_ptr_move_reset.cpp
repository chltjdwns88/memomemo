#include <iostream>
#include <memory>


// move연산자를 사용해 shared_ptr 포인터를 이동 시킬 수 있음
// 이동 후 기존 shared_ptr의 카운트는 0이됨

int main()
{
    std::shared_ptr<int> s1 = std::make_shared<int>(10);

    std::cout << "s1 : " << s1.use_count() << '\n';

    std::shared_ptr<int> s2;
    std::cout << "s2 : " << s2.use_count() << '\n';

    s2 = std::move(s1);

    std::cout << "after s2 = std::move(s1)  " << '\n';
    std::cout << "s1 : " << s1.use_count() << " s2 : " << s2.use_count() << '\n';
    std::cout << "s2 value : " << *s2 << '\n';



    std::cout << '\n';
    std::cout << "reset()" << '\n';
    std::cout << '\n';

    std::cout << "basic reset\n";
    std::shared_ptr<int> b1 = std::make_shared<int>(10);
    std::cout << "b1 : " << b1.use_count() << '\n';
    std::shared_ptr<int> b2 = b1;
    std::cout << "b1 : " << b1.use_count() << " b2 : " << b2.use_count() << '\n';
    b1.reset();
    std::cout << "b1 : " << b1.use_count() << " b2 : " << b2.use_count() << '\n'; 

    std::cout << "\n\nwith parameter\n";
    std::shared_ptr<int> wp = std::make_shared<int>(10);
    std::cout << "wp.use_count() : " << wp.use_count() << " *wp : " << *wp << '\n';
    wp.reset(new int(40)); // reset으로 0이 됨가 동시에 새로운 포인터 할당+1
    std::cout << "wp.use_count() : " << wp.use_count() << " *wp : " << *wp << '\n';

    std::cout << "\n\nnullptr\n";
    std::cout << "wp.use_count() : " << wp.use_count() << " *wp : " << *wp << '\n';
    wp = nullptr;
    std::cout << "after nullptr\n";
    std::cout << "wp.use_count() : " << wp.use_count() << '\n';
    return 0;
}