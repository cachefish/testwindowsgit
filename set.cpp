#include<iostream>
#include<set>

using namespace std;

void display(const set<int> &c)
{
    typename set<int>::const_iterator sit = c.begin();
    while(sit!=c.end()){
        cout<<*sit<<" ";
        ++sit;
    }
    cout<<endl;
}

void test1()
{
    int array[10] = {3,4,5,2,6,7,8,2,3,10};
    set<int> setInt(array,array+10);
    display(setInt);
    set<int>::iterator it = setInt.begin();
    //添加元素
    pair<set<int>::iterator,bool> ret = setInt.insert(1);
    if(ret.second)
    {
        cout<<"添加成功"<<endl;
        cout<<"*(ret.first)="<<*(ret.first)<<endl;
    }else{
        cout<<"添加失败,set之中已经有了相应的值"<<endl;
    }
    display(setInt);
}


int main()
{
    test1();
    return 0;
}
