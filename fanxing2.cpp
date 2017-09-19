#include<iostream>
using namespace std;
template<typename T>
T * My_find(T *array,T n,T x){
    T* p = array;
    int i;
    for(i=0;i<n;i++){
        if(*p == x){
            return p;
        }
        p++;
    }
    return 0;
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,10};
    int *result = My_find<int>(a,10,3);
    cout<<(*result)<<"\n"<<endl;
    return 0;
}
