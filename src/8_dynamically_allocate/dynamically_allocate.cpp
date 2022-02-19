// use smart pointers more!
// 1. don't know how many objects needed
// 2. don't know exact type of objects
// 3. want to share data between different objects

# include <iostream>
# include <memory>
# include <string>
# include <vector>
# include <stdexcept>


using std::shared_ptr; using std::make_shared;
using std::unique_ptr;
using std::weak_ptr;


using std::string; using std::vector;
using std::cout; using std::endl;

class StrBlob
{
    public:
        typedef vector<string>::size_type ST;

        StrBlob(): data_(make_shared<vector<string>>()){}
        StrBlob(std::initializer_list<string> il):
                data_(make_shared<vector<string>>(il)){}

        ST Size() const {return data_->size();}
        bool isEmpty() const {return data_->empty();}
        void PushBack(const string &t) {data_->push_back(t);}
        string &Front();
        string &Back();
        void PopBack();
        const string &Front() const;
        const string &Back() const;

    private:
        shared_ptr<vector<string>> data_;
        void Check(ST i, const string &msg) const;
};

void StrBlob::Check(ST i, const string &msg) const
{
    if (i >= data_->size()) throw std::out_of_range(msg);
}

string &StrBlob::Front()
{
    Check(0, "front requested on empty StrBlob");
    return data_->front();
}

string &StrBlob::Back()
{
    Check(0, "back requested on empty StrBlob");
    return data_->back();
}

const string &StrBlob::Front() const
{
    Check(0, "front requested on empty StrBlob");
    return data_->front();
}

const string &StrBlob::Back() const
{
    Check(0, "back requested on empty StrBlob");
    return data_->back();
}

void StrBlob::PopBack()
{
    Check(0, "pop_back on empty StrBlob");
    data_->pop_back();
}







int main()
{
    shared_ptr<string> p1;
    shared_ptr<vector<int>> p2;

    if (p1 && p1->empty()) *p1 = "hello";
    // p1 = point to some object ? true : false
    // p1->empty(): is p1 points to an empty string?

    // make_shared: highly recommended
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(5,'9');
    shared_ptr<int> p5 = make_shared<int>();
    auto p6 = make_shared<vector<string>>(std::initializer_list<string>{"hello", "hi"});

    auto q3(p3); // p3 -> [42] <- q3

    // reference count: if no pointer aiming to one object, release its memory
    // always erase unnecessary items in containers

    // StrBlob
    StrBlob a = StrBlob({"hello", "my", "world"});
    


    return 0;
}