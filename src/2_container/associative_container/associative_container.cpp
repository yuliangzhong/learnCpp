// map: [key--value] * n
// what's the value of key?
// set: {key1, key2...}
// does key exist?

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <set> // set; multiset
# include <unordered_set>
# include <utility> // pair

using std::string;
using std::vector;
using std::map; 
using std::set; using std::multiset;
using std::pair;
using std::cin; using std::cout;
using std::endl;

typedef vector<int>::size_type ST;

struct SalesData
{
    string isbn_;
};

inline bool CompareIsbn(const SalesData &d1, const SalesData &d2)
{
    return d1.isbn_ < d2.isbn_;
}

void RemoveWord(map<string, size_t> &words, const string &s)
{   // erase(key_type s) -> bool ifFound
    if(words.erase(s))  cout<<"OK, \""<<s<<"\" removed\n";
    else cout<<"Oh, \""<<s<<"\" is not found"<<endl;
}

pair<string, int> Process(vector<string> &v)
{
    if (!v.empty()) return {v.back(), v.back().size()}; // init by { }
    // or return pair<string, int>(v.back(), v.back().size())
    // or return make_pair(v.back(), v.back().size())
    else return pair<string, int>(); 
}

int main()
{
    // string key; size_t value
    // init by {}
    map<string, size_t> word_cnt = {{"here", 1}, {"there", 2}};
    // set<string> exclude = {"time", "hello"};

    // string word;
    // int cnt = 0;
    // while (cin>>word && cnt<5)   
    // {
    //     if (exclude.find(word) == exclude.end()) // use its own find()
    //     // also, use count() -> a number
    //     {   // add an item by [] operator
    //         ++word_cnt[word]; // if no "word", new one, 0->1; else, ++value
    //         ++cnt;
    //     }
    //     // c[key]:-> key exists? return value of key : add one, return init value
    //     // c.at(key):-> key exists? return value of key : throw "out_of_range" exception 
    // }
    // for (const auto &w : word_cnt)
    // {   // first is key; second is value
    //     cout<<w.first<<" occurs "<<w.second<< (w.second>1?" times":" time")<<endl;
    // }

    vector<int> ivec;
    for (ST i=0; i!=10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    // init set/map by a vector
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout<<ivec.size()<<" "<<iset.size()<<" "<<miset.size()<<endl;
    
    // key should equip "<" 
    // attention: <<C++ primer5 CN>> has a translation error! Not <=!
    multiset<SalesData, decltype(CompareIsbn) * > bookstore(CompareIsbn); // function pointer
    // equivalent to "bookstore(&CompareIsbn)"
    typedef bool F (const SalesData &, const SalesData &); // function type
    F *p = CompareIsbn; // p is a function pointer
    set<SalesData, F * > bookstore2(p);

    // the items of map/set are pairs
    // pair.first, pair.second
    pair<string, string> anon;
    pair<string, size_t> word_count;
    pair<string, vector<int>> line;
    pair<string, string> author{"James", "Joyce"};

    set<string>::value_type v1; // string
    set<string>::key_type v2; // string
    map<string, int>::value_type v3; // pair<const string, int>
    map<string, int>::key_type v4; // string
    map<string, int>::mapped_type v5; // int

    // iterator of associative container
    auto map_it = word_cnt.begin();
    cout<<map_it->first<<" "<<map_it->second<<endl;
    ++map_it->second; // right
    // map_it->first = "new key"; // wrong, because key is const
    auto set_it = iset.begin();
    if (set_it != iset.end()) cout<<*set_it<<endl;
    // *set_it = 43; // wrong

    // use insert to add items
    iset.clear();
    vector<int> ivec2 = {2,3,4,8,10};
    iset.insert(ivec2.begin(), ivec2.end());
    iset.insert({1,2,3,4,5});

    for (const auto &i : iset) cout<<i<<" ";
    cout<<endl;

    // use insert() -> (auto iterator, bool ifSuccess) 
    word_cnt.insert({"word", 1});
    word_cnt.insert(std::make_pair("good", 7));
    word_cnt.insert(pair<string, size_t>("pair", 5));
    word_cnt.insert(map<string, size_t>::value_type("fine", 4));

    for (const auto &i : word_cnt) cout<<"{"<<i.first<<", "<<i.second<<"} ";
    cout<<endl;

    RemoveWord(word_cnt, "here");
    RemoveWord(word_cnt, "pig");
    
    // C++11 -> unordered associative container
    std::unordered_set<int> uiset({7,8,5,80,6,9,10});
    for (const auto &i : uiset) cout<<i<<" ";
    cout<<endl;

    for (int t=0; t!=uiset.bucket_count(); ++t) cout<<uiset.bucket_size(t)<<" ";
    cout<<endl;


    return 0;
}