#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void bubble_sort(int arr[], int size){
    int sz = size;
    int i = 0;
    for(i; i<sz-1; i++){
        int j = 0;//�����±�
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
    //��ַ��������������ʹ�С��int 4byte��32bit��
    // }
    // std::cout << strlen(arr2) << std::endl;
    //strlen����ַ���û���ս��'\0'���ص������������������
    
    //���������������Ԫ�ص�ַ
    // std::cout<< *arr << std::endl;
    
    // bubble_sort(arr,t);
    // print_arr(arr,t);
    //���ݵ����׵�ַ����ָ�룬�������޷��õ������ʵ�ʴ�С�����Ҫ��ʽ����t

    vector<int> str_a = {1,3,5};
    
    // vector<int> str_b(4, 5); 
    // // std::cout << str_b.size() <<std::endl;  //4
    // // std::cout << str_b.capacity() <<std::endl;  //4
    
    // //����Ԫ��
    // str_a.push_back(6);
    // str_a.push_back(11);
    // str_a.push_back(16);
    // std::cout << str_a.size() <<std::endl;  //6
    // std::cout << str_a.capacity() <<std::endl;  //6
    
    // //�������һ��Ԫ��16
    // str_a.pop_back();
    // std::cout << str_a[0] << ',' << str_a[4]<< std::endl;//1,11

    // for(int item : str_a){
    //     std::cout << item <<std::endl;
    // }
    // if (!str_a.empty()){
    //     std::cout << "Not empty" <<std::endl;
    // }

    // str_a.insert(str_a.begin() + 4, 99);
    //index=4λ�ò���99
    //begin()end()�����޸ģ�cbegin()cend()�������޸�

    // for(int i = 0; i<30; i++){
    //     str_a.push_back(i+3);
    // }
    
    // str_a.shrink_to_fit();
    //std::vector::shrink_to_fit()���Խ��������������������С��ƥ�䡣

    //unsigned�����޷����� unsigned int

    //�������������Χ��at() ���׳� std::out_of_range �쳣
    try{
        std::cout<< str_a.at(10) << std::endl;
    }catch(const std::out_of_range& e){
        std::cerr<< e.what() << std::endl;
        std::cout<< e.what() << std::endl;

    }

    //eraseɾ���Ŀ������Ϊ����Ұ�
    str_a.erase(str_a.begin());
    // str_a.erase(str_a.begin(), str_a.begin()+1);
    
    int size_a = str_a.size();
    std::cout<< size_a << std::endl;
    print_vector(str_a, size_a);


    return 0;
    
}