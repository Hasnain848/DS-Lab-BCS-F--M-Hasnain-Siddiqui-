#include<iostream>
#include<algorithm>
using namespace std;
class product{
    string name;
    double price;
    string discrip;
    bool availablity;
    public:
    product(){name="",price=0;discrip="";availablity=false;}
    product(string name,double price,string discrip,bool available):name(name),price(price),
    discrip(discrip),availablity(available){}
    product(const product& obj){
        name = obj.name;
        price = obj.price;
        discrip = obj.discrip;
        availablity = obj.availablity;
    }
    product& operator=(const product& obj){
        if (this != &obj){
            name = obj.name;
            price = obj.price;
            discrip = obj.discrip;
            availablity = obj.availablity;
        }
        return *this;
    }
    string getname(){return name;}
    double getprice(){return price;}
    string getdiscrip(){return discrip;}
    bool getavailable(){return availablity;}
    void display(){
        cout<<name<<" - $"<<price<<endl;
    }
    
};
int partition(product p[],int low,int high){
    double pivot = p[low].getprice();
    int i = low + 1;
    int j = high;
    while(i<=j){
        while(i<=high && p[i].getprice()<=pivot)
            i++;
        while(j>=low && p[j].getprice()>pivot)
            j--;
        if(i<j){
            swap(p[i],p[j]);
        }
    }
    swap(p[j],p[low]);

    return j;
}

void quickSort(product p[],int low,int high) {
    if (low < high) {
        int pi = partition(p,low,high);

        quickSort(p, low, pi - 1);
        quickSort(p, pi + 1, high);
    }
}
int main(){
    product p[3]={product("Product 1",10.99,"This is product 1",true),
                  product("Product 2",5.99,"This is product 2",false),
                  product("Product 3",2.99,"This is product 3",true)};
                  quickSort(p,0,2);
                  cout<<"Products Sorted by price"<<endl;
        for(int i=0;i<3;i++){
            p[i].display();
        }
    
    

}