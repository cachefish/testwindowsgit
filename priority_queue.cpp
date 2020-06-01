#include<iostream>
#include<queue>

using namespace std;

int test0()
{
    //默认情况下，是按小于符号进行比较的，得到的是一个降序的排列

    //优先级队列底层是堆排序，默认时大顶堆
    //当堆顶的元素与新添加的元素进行比较，返回值为true时，则将新添加的元素替换队顶的元素，原来队顶的元素进行堆的调整

    int arr[10] = {7,2,4,6,78,9,1,45,3,56};
    priority_queue<int> pque;

    for(int idx = 0;idx!=10;++idx)
    {
        pque.push(arr[idx]);
        cout<<"当前优先级最高的是"<<pque.top()<<endl;
    }
    while (!pque.empty())
    {
        cout<<pque.top()<<" ";
        pque.pop();
        /* code */
    }
    cout<<endl;
    
}

int test1()
{
    int arr[10] = {7,2,4,6,78,9,1,45,3,56};
    priority_queue<int,vector<int>,std::greater<int>> pque;

    for(int idx = 0;idx!=10;++idx)
    {
        pque.push(arr[idx]);
        cout<<"当前优先级最高的是"<<pque.top()<<endl;
    }
    while (!pque.empty())
    {
        cout<<pque.top()<<" ";
        pque.pop();
        /* code */
    }
    cout<<endl;
}

int main()
{
    test1();
    return 0;
}