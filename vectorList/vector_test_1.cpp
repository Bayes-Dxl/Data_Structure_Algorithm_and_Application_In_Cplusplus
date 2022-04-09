//
// Created by Hxy on 2022/3/30.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include <array>

using namespace std;

int main()
{
    vector<char>vec;
    vector<char>::iterator ite;
    vector<char>::iterator p;
    vec.push_back('A');
    vec.push_back('B');
    vec.push_back('C');
    vec.push_back('A');
    vec.push_back('D');
    vec.push_back('E');
    vec.push_back('F');
    vec.push_back('G');
    vec.push_back('J');
    vec.push_back('A');
    // vec.erase(vec.begin(),vec.end());
//     p=vec.erase(remove(vec.begin(),vec.end(),'A'),vec.end());
//    for (auto i : vec)
//        cout << i << " ";
//    cout << endl;
     p = remove(vec.begin()+1,vec.end(),'A');
     cout << *p <<endl;
     cout << *(p+1) << endl;

//    cout<<vec.end()-p<<endl;
//    cout<<*p<<endl;
//    cout<<*(p+1)<<endl;
//    cout<<*(p+2)<<endl;
//
    for(ite=vec.begin();ite!=vec.end();++ite)
        cout<<*ite<<" ";



    cout << "-----------------------" << endl;
    auto temp = new std::vector<int>;
    temp->push_back(3);
    temp->push_back(4);
    auto temp1 = new std::vector<int>;

    temp1->push_back(1);
    temp1->push_back(2);

    temp1->reserve(5);
    temp1 = temp;
    for(auto i : *temp1)
        cout << i << " ";

    temp1->resize(10);
    for(auto i : *temp1)
        cout << i << " ";

    std::array<std::string, 5> words     {"one","two","three","four","five"};
    std::vector<std::string> words_copy {std::begin(words, std::end(words)};





    return 0;
}