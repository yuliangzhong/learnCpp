# include "dynamically_allocate.hpp"

using namespace dynamically_allocate_ns;

int main()
{
    shared_ptr<string> p1;
    shared_ptr<vector<int>> p2;

    if (p1 && p1->empty()) *p1 = "hello";
    // p1 = point to some object ? true : false
    // p1->empty(): is p1 points to an empty string?

    // make_shared: highly recommended
    shared_ptr<int> p3 = make_shared<int>(42); // init
    shared_ptr<string> p4 = make_shared<string>(5,'9');
    shared_ptr<int> p5 = make_shared<int>();
    // vector should be initialized by initializer_list<>{}
    auto p6 = make_shared<vector<string>>(std::initializer_list<string>{"hello", "hi"});

    shared_ptr<int> q3(p3); // p3 -> [42] <- q3 // = auto q3(p3)
    bool ifUnique = q3.unique();
    int users = q3.use_count(); // can be slow
    cout<<users<<" users\n";
    // reference count: if no pointer aiming to one object, release its memory
    // always erase unnecessary items in containers

    // StrBlob
    StrBlob strblob = StrBlob({"hello", "my", "world"});
    
    // new delete <- had better not use them!
    // int *pi = new int(1024);
    // vector<int> *pv = new vector<int>{0,1,2,3};
    // delete pi;
    // delete pv;
    // auto pa1 = new auto(strblob);
    // auto pa2 = new decltype(strblob);
    // delete pa1; delete pa2;
    // int *pi3 = new (std::nothrow) int; // return NULL pointer if no memory
    // delete pi3;
    // after "delete", pointers become "dangling pointers"

    // deleter
    {
        shared_ptr<int> pint(new int[12], Deleter);
        shared_ptr<int> plam(new int[5], [](int *p){ delete[] p; cout<<"array safely deleted by lambda\n";});
    }

    // unique_ptr
    unique_ptr<double> pd1;
    unique_ptr<double> pd2(new double(42.42));
    unique_ptr<double> pd3 = make_unique<double>(42.42); // c++ 14 required
    // no copy; no "="
    // use release
    unique_ptr<double> pd4(pd2.release());
    unique_ptr<double> pd5(new double(53.53));
    pd4.reset(pd5.release());
    // pd4.release(); // Danger! object released; pointer lost;

    // can return unique_ptr i.e. can copy from a dying local unique_ptr
    auto pd6 = Clone(64.09); 
    cout<<*pd6<<endl;

    // specify function pointer type when using deleter
    unique_ptr<int, decltype(Deleter)*> pd7(new int[5], Deleter);

    // weak_ptr
    shared_ptr<int> pi = make_shared<int>(42);
    weak_ptr<int> wp(pi);
    wp.reset(); // wp -> null
    wp = p3;
    cout<<wp.use_count()<<endl; // shared_ptr numbers
    cout<<(wp.expired() ? "True" : "False")<<endl; // use_count = 0: true; else false
    cout<<*wp.lock()<<endl; // use .lock() to get objects

    



    return 0;
}