#include <iostream>
#include <memory>

int main()
{
    int* buffer1 = new int[100];
    std::shared_ptr<int> s1;

    s1.reset(buffer1);
    std::cout << s1.use_count() << '\n';

    s1.reset(buffer1, [](int* ref){delete []ref; std::cout << "success delete\n";});
    std::cout << "s1 : " << s1.use_count() << " *s1 : " << *s1 << '\n';
    return 0;
}