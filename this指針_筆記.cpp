#include <iostream>
#include <thread>

using namespace std;

class this_test {//沒錯,class的確封裝了「數據」和「方法」
                 //但數據和方法是分開儲存的
                 //數據每個instance都各儲存一份,但方法只有一份在代碼區
private:
    int num;
public:
    void set_num(int num) {//當比如test1調用set_num,
                           //compiler就會把test1這個對像的地址傳給class中的set_num方法
                           //使set_num知道誰在調用它
        this->num = num;   //而這個this是額外的,使set_num知道應該把num賦值給&test1->num
                           //而不是就近原則的num=num,自己賦值給自己
    }                      
    int return_num() {
        return this->num;//如test1調用return_num,則返回&test1->num
                         //不然return_num不知應調用哪裡的num而報錯
    }
};

int main() {
    this_test test1;
    test1.set_num(100);
    cout << test1.return_num() << endl;

    this_test test2;
    test2.set_num(200);
    cout << test2.return_num() << endl;
    return 0;
}
