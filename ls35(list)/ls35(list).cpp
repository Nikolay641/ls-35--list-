#include "Node.h"
#include "MyList.h"

int main()
{
    using namespace MyList;

    //Node<int> first(7); //item = 7, next = &second
    //Node<int> second(12); //item = 12, next = &third
    //first.next = &second;
    //Node<int> third(-6); //item = -6, next = &fourth
    //second.next = &third;
    //Node<int> fourth(123); //item = 123, next = nullptr
    //third.next = &fourth;
    ////Обробка списку
    //Node<int>* p = &first;
    //while (p != nullptr) {
    //    cout << p->item << " ";
    //    p = p->next;
    //}

    //DList<int> a;
    //a.push_back(7);
    //a.push_back(12);
    //a.push_back(-6);
    //a.push_back(123);
    //a.showReverseInfo();
    //cout << endl;
    //cout << a.search(7) << endl << endl;
    //cout << a.search(8) << endl << endl;

    DList<int> a;
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);
    a.push_front(5);
    a.showInfo();
    cout << "---------------\n\n";
    a.insertAfter(5, 6);
    a.insertBefore(5, 4);
    a.showInfo();
    cout << "---------------\n\n";
    a.erase(10);
    a.showInfo();
    cout << endl;
}