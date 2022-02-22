# ifndef _DYNAMICALLY_ALLOCATE_H_
# define _DYNAMICALLY_ALLOCATE_H_

// use shared_ptr
// 1. don't know how many objects needed
// 2. don't know exact type of objects
// 3. want to share data between different objects

# include <iostream>
# include <memory>
# include <string>
# include <vector>
# include <stdexcept>

namespace dynamically_allocate_ns{

using std::shared_ptr; using std::make_shared;
using std::unique_ptr; using std::make_unique;
using std::weak_ptr;

using std::string; using std::vector;
using std::cout; using std::endl;

void Deleter(int *p)
{
    delete[] p;
    cout<<"array safely deleted"<<endl;
}

unique_ptr<double> Clone(double d)
{
    return make_unique<double>(d);
}

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


} // namespace dynamically_allocate_ns




# endif