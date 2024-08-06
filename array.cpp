#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void bubble_sort(int arr[], int size){
    int sz = size;
    int i = 0;
    for(i; i<sz-1; i++){
        int j = 0;//数组下标
        for(j; j<sz-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
}
void print_arr(int arr[], int size){
    int i = 0;  
    for(i;i<size;i++){
        std::cout<< arr[i] <<std::endl;
    }
}
void print_vector(std::vector<int> &arr, int size){
    int i = 0;  
    for(i;i<size;i++){
        std::cout<< arr[i] <<std::endl;
    }
}
int main(){
    // std::cout << "yyy" <<std::endl;
    int arr[5] = {1,10,3,9,5};
    char arr2[] = {'1','b','4','6'};
    int t = sizeof(arr) / sizeof(arr[0]);
    // std::cout << t << std::endl;
    
    // for(int i = 0; i<t; i++)
    // {
    //     std::cout << &arr[i] << std::endl;
    //地址间隔都是数据类型大小，int 4byte（32bit）
    // }
    // std::cout << strlen(arr2) << std::endl;
    //strlen如果字符串没有终结符'\0'返回的数据理论上是随机的
    
    //数组名是数组的首元素地址
    // std::cout<< *arr << std::endl;
    
    // bubble_sort(arr,t);
    // print_arr(arr,t);
    //传递的是首地址，是指针，函数内无法得到数组的实际大小，因此要显式传入t

    vector<int> str_a = {1,3,5};
    
    // vector<int> str_b(4, 5); 
    // // std::cout << str_b.size() <<std::endl;  //4
    // // std::cout << str_b.capacity() <<std::endl;  //4
    
    // //加入元素
    // str_a.push_back(6);
    // str_a.push_back(11);
    // str_a.push_back(16);
    // std::cout << str_a.size() <<std::endl;  //6
    // std::cout << str_a.capacity() <<std::endl;  //6
    
    // //弹出最后一个元素16
    // str_a.pop_back();
    // std::cout << str_a[0] << ',' << str_a[4]<< std::endl;//1,11

    // for(int item : str_a){
    //     std::cout << item <<std::endl;
    // }
    // if (!str_a.empty()){
    //     std::cout << "Not empty" <<std::endl;
    // }

    // str_a.insert(str_a.begin() + 4, 99);
    //index=4位置插入99
    //begin()end()可以修改，cbegin()cend()不可以修改

    // for(int i = 0; i<30; i++){
    //     str_a.push_back(i+3);
    // }
    
    // str_a.shrink_to_fit();
    //std::vector::shrink_to_fit()尝试将容器的容量调整到与大小相匹配。

    //unsigned声明无符号数 unsigned int

    //如果索引超出范围，at() 会抛出 std::out_of_range 异常
    try{
        std::cout<< str_a.at(10) << std::endl;
    }catch(const std::out_of_range& e){
        std::cerr<< e.what() << std::endl;
        std::cout<< e.what() << std::endl;

    }

    //erase删除的可以理解为左闭右包
    str_a.erase(str_a.begin());
    // str_a.erase(str_a.begin(), str_a.begin()+1);
    
    int size_a = str_a.size();
    std::cout<< size_a << std::endl;
    print_vector(str_a, size_a);


    return 0;
    
}