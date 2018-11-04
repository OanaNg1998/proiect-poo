#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include <limits>




int main()
{
   Matrix M3(3,3),M4(2,2);
   std::cout<<" I Matrice este :"<<std::endl;
   std::cin >>M3;
   std::cout<<" A-II-a matrice este :"<<std::endl;
   std::cin >>M4;



//Operatori cu exceptii:

try {
    int pow;
    std::cout<<"Puterea este :"<<std::endl;
    std::cin>>pow;
    std::cout<<"Matricea I la puterea data este :"<<std::endl;
    std::cout<<(M3^pow)<<std::endl;
    }
catch(int excep) {
                    if(excep==-1) std::cout<<"Obiectul din clasa Matrix ridicat la puterea pow depaseste limita maxima impusa de tipul de date double"<<std::endl;
                    if(excep==0) std::cout<<"Matricea nu indeplineste regulile ridicarii la putere,deci operatorul ^ nu se poate realiza"<<std::endl;
                 }


try {
     std::cout<<" I Matrice *= a II-a Matrice"<<std::endl;
     M3*=M4;
     std::cout<<"Matricea devine :"<<std::endl<<M3;
    }
catch(int deviation) {
                        if(deviation==1) std::cout<<"Cei doi operanzi de tip Matrix nu respecta regulile operatorului *="<<std::endl;
                     }



try{
        double variable;
        std::cout<<"--- Scalarul cu care vrei sa imparti ---"<<std::endl;
        std::cin>>variable;
        M3/=variable;
        std::cout<<" I Matrice /= scalar "<<std::endl<<M3<<std::endl;
   }
catch(int error) {
                    if(error==2) std::cout<<"Scalarul cu care este impartita matricea este nul"<<std::endl;
                 }




//Operatori compusi de atribuire


 Matrix M5(3,3);
try{
        std::cout<<"A III-a matrice:"<<std::endl;
        std::cin>>M5;
        std::cout<<" I Matrice += a III-a Matrice"<<std::endl;
        std::cout<<(M3+=M5)<<std::endl;
   }
catch(int error) {
                    if(error==3) std::cout<<"Cele 2 obiecte din clasa Matrix nu respecta regulile adunarii,deci operatorul += nu se poate realiza"<<std::endl;
                 }
 std::cout<<" A III-a Matrice += scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var2;
 std::cin>>var2;
 std::cout<<(M5+=var2)<<std::endl;
 try{
        std::cout<<"A III-a Matrice -= I Matrice:"<<std::endl;
        std::cout<<(M5-=M3)<<std::endl;
    }
 catch(int deviation) {
                        if(deviation==4) std::cout<<"Cele 2 obiecte din clasa Matrix nu respecta regulile scaderii,deci operatorul -= nu se poate realiza"<<std::endl;
                      }
 std::cout<<"A III-a Matrice -= scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var3;
 std::cin>>var3;
 std::cout<<(M5-=var3)<<std::endl;
 std::cout<<"A III-a Matrice *= scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var4;
 std::cin>>var4;
 std::cout<<(M5*=var4)<<std::endl;
 std::cout<<"A III-a Matrice /= scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var5;
 std::cin>>var5;
 std::cout<<(M5/=var5)<<std::endl;



//Operatori unari:



  std::cout<<" + I Matrice:"<<std::endl;
  std::cout<<+M3<<std::endl;
  std::cout<<" - I Matrice:"<<std::endl;
  std::cout<<-M3<<std::endl;



//Operatori aritmetici binari:


try{
        std::cout<<" I Matrice + a II-a Matrice:"<<std::endl;
        std::cout<<M3+M4<<std::endl;
   }
catch(int excep){
                    if(excep==5) std::cout<<"Matricile nu sunt de acelasi tip,deci nu se poate realiza operatorul +"<<std::endl;
                }
 std::cout<<" I Matrice + scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var6;
 std::cin>>var6;
 std::cout<<M3+var6<<std::endl;
 std::cout<<" scalar + I Matrice :"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var7;
 std::cin>>var7;
 std::cout<<var7+M3<<std::endl;
 try{
        std::cout<<" I Matrice - a II-a Matrice :"<<std::endl;
        std::cout<<M3-M4<<std::endl;
    }
 catch(int deviation) {
                            if(deviation==6) std::cout<<"Matricile nu sunt de acelasi tip,deci nu se poate realiza operatorul -"<<std::endl;
                      }
 std::cout<<" I Matrice - scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var8;
 std::cin>>var8;
 std::cout<<M3-var8<<std::endl;
 std::cout<<" scalar - I Matrice :"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var9;
 std::cin>>var9;
 std::cout<<var9-M3<<std::endl;
 try {
        std::cout<<" I Matrice * a II-a Matrice:"<<std::endl;
        std::cout<<M3*M4<<std::endl;
 }
 catch(int excep) {
                    if(excep==7) std::cout<<"Matricile nu respecta regulile inmultirii,deci operatorul * nu se poate realiza"<<std::endl;
                  }
 std::cout<<" I Matrice * scalar:"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var10;
 std::cin>>var10;
 std::cout<<M3*var10<<std::endl;
 std::cout<<" scalar * I Matrice :"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var11;
 std::cin>>var11;
 std::cout<<var11*M3<<std::endl;
 try {
        std::cout<<" I Matrice / scalar:"<<std::endl;
        std::cout<<"Scalarul este :"<<std::endl;
        double var12;
        std::cin>>var12;
        std::cout<<M3/var12<<std::endl;
     }
 catch(int excep){
                    if(excep==8) std::cout<<" Scalarul este nul,deci operatorul / nu se poate realiza"<<std::endl;
                 }
 std::cout<<" scalar / I Matrice :"<<std::endl;
 std::cout<<"Scalarul este :"<<std::endl;
 double var13;
 std::cin>>var13;
 std::cout<<var13/M3<<std::endl;





//Alti operatori



 std::cout<<"I Matrice [pozitie]:"<<std::endl;
 std::cout<<"Pozitia este :"<<std::endl;
 double var14;
 std::cin>>var14;
 std::cout<<M3[var14]<<std::endl;



//Operatori relationali


 std::cout<<"I Matrice == a II-a Matrice:"<<std::endl;
 std::cout<<(M3==M4)<<std::endl;
 std::cout<<"I Matrice != a II-a Matrice:"<<std::endl;
 std::cout<<(M3!=M4)<<std::endl;




    return 0;
}
