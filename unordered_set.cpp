#include<iostream>
#include<unordered_set>
using namespace std;

class Point
{
public:
    Point(int ix = 0,int iy =0):_ix(ix),_iy(iy){
        cout<<"Point(int ix =0,int iy =0)"<<endl;
    }
    int getX()const{return _ix;}
    int getY()const{return _iy;}
    ~Point()
    {
        cout<<"~Point"<<endl;
    }
    friend ostream&operator <<(ostream &os,const Point&rhs);
    friend bool operator==(const Point&lhs,const Point&rhs);
private:
    int _ix;
    int _iy;
};

ostream&operator <<(ostream &os,const Point&rhs)
{
    os<<"("<<rhs._ix<<"."<<rhs._iy<<")"<<endl;
    return os;
}
bool operator==(const Point&lhs,const Point&rhs)
{
    return lhs._ix==rhs._ix&&lhs._iy==rhs._iy;
}

namespace std{
    template<>
    struct hash<Point>
    {
        size_t operator()(const Point&lhs)const
        {
            return std::hash<int>()(lhs.getX()<<1)^
                (std::hash<int>()(lhs.getY())>>1);
        }
        /* data */
    };
    
}

struct PointHasher{
    size_t operator()(const Point&lhs)const
    {
        return std::hash<int>()(lhs.getX()<<1)^
                (std::hash<int>()(lhs.getY())>>1);
    }
};

void test0()
{
    unordered_set<int> set{5,3,2,1,2,4,6,8,9,0};
    for(auto &elem:set){
        cout<<elem<<" ";
    }
}

void test1(void)
{
    unordered_set<Point> sets{
        Point(1,2),
        Point(3,4),
        Point(1,2),
        Point(5,6),
    };
    for(auto &elem:sets)
    {
        cout<<elem<<" ";
    }
}

void test2(void)
{
    unordered_set<Point,PointHasher> sets{
        Point(1,2),
        Point(3,4),
        Point(1,2),
        Point(5,6),
    };
    for(auto &elem:sets)
    {
        cout<<elem<<" ";
    }
}

int main()
{
    test2();
    return 0;
}