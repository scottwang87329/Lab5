#include <iostream> 
#include <string> 
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std; 

class HugeInt { 

friend ostream &operator << (ostream &out, const HugeInt &huge)
{
  
  for(int i=0;i<huge.hugevector.size();i++){
  out << huge.hugevector[i];
  }

  return out; 

}  



friend istream &operator >> (istream &in, HugeInt &huge)
{
   
   string temp;
   in>>temp;
   
   for(int i=0;i<temp.length();i++){
     int int_temp;
     stringstream ss;
     ss<<temp.substr(i,1);
     ss>>int_temp;
     huge.hugevector.push_back(int_temp);
   }

}



private: 
   vector<int>hugevector;



public:
   HugeInt(){ }

   HugeInt(int number){
   string temp;
   stringstream ss;
   ss<<number;
   ss>>temp;

   for(int i=0;i<temp.length();i++){
    
   int int_temp;

   stringstream ss;
   ss<<temp.substr(i,1);
   ss>>int_temp;

   hugevector.push_back(int_temp);
   }
 }

   HugeInt(string str){
   for(int i=0;i<str.length();i++){
   int temp;

   stringstream ss;
   ss<<str.substr(i,1);
   ss>>temp;

   hugevector.push_back(temp);
   }
   
 }

 
  
   HugeInt& operator=(const HugeInt &huge){

   (*this).hugevector=huge.hugevector;
   return *this;

  }


   HugeInt operator+(const HugeInt &huge){
   
   vector<int>temp_answer;
   
   int carry=0;
   for(int i=(*this).hugevector.size()-1,j=huge.hugevector.size()-1;i>=0&&j>=0;i--,j--){

   if(carry+(*this).hugevector[i]+huge.hugevector[j]<=9){
   temp_answer.push_back(carry+(*this).hugevector[i]+huge.hugevector[j]);
   carry=0;}
  
   if(carry+(*this).hugevector[i]+huge.hugevector[j]>=10){
   temp_answer.push_back(carry+(*this).hugevector[i]+huge.hugevector[j]-10);
   carry=1;}

   }
   

   if((*this).hugevector.size()>huge.hugevector.size()){
    if(carry==1){
        temp_answer.push_back(1+(*this).hugevector[(*this).hugevector.size()-huge.hugevector.size()-1]);
        for(int i=(*this).hugevector.size()-huge.hugevector.size()-2;i>=0;i--){temp_answer.push_back((*this).hugevector[i]);}                                                         
                  }
    if(carry==0){
        for(int i=(*this).hugevector.size()-huge.hugevector.size()-1;i>=0;i--){temp_answer.push_back((*this).hugevector[i]);}                                                         
                  }
    }


   if(huge.hugevector.size()>(*this).hugevector.size()){
    if(carry==1){
        temp_answer.push_back(1+huge.hugevector[huge.hugevector.size()-(*this).hugevector.size()-1]);
        for(int i=huge.hugevector.size()-(*this).hugevector.size()-2;i>=0;i--){temp_answer.push_back(huge.hugevector[i]);}                                                         
                  }
    if(carry==0){
        for(int i=huge.hugevector.size()-(*this).hugevector.size()-1;i>=0;i--){temp_answer.push_back(huge.hugevector[i]);}                                                         
                  }
    }



   if(huge.hugevector.size()==(*this).hugevector.size()){
    if(carry==1){temp_answer.push_back(1);}
   }

   
   HugeInt real_answer;
   for(int i=temp_answer.size()-1;i>=0;i--){
   real_answer.hugevector.push_back(temp_answer[i]);
   }
   
   
   return real_answer;
 }


    

   HugeInt operator-(const HugeInt &huge){
   
   vector<int>temp_answer;
   
   int carry=0;
   for(int i=(*this).hugevector.size()-1,j=huge.hugevector.size()-1;i>=0&&j>=0;i--,j--){

   if(carry+(*this).hugevector[i]-huge.hugevector[j]>=0){
   temp_answer.push_back(carry+(*this).hugevector[i]-huge.hugevector[j]);
   carry=0;}
  
   if(carry+(*this).hugevector[i]-huge.hugevector[j]<0){
   temp_answer.push_back(10+carry+(*this).hugevector[i]-huge.hugevector[j]);
   carry=-1;}

   }
   

   
   if((*this).hugevector.size()>huge.hugevector.size()){
    if(carry==0){
        for(int i=(*this).hugevector.size()-huge.hugevector.size()-1;i>=0;i--){temp_answer.push_back((*this).hugevector[i]);}                                                         
                  }
    if(carry==-1){
        temp_answer.push_back(-1+(*this).hugevector[(*this).hugevector.size()-huge.hugevector.size()-1]);
        for(int i=(*this).hugevector.size()-huge.hugevector.size()-2;i>=0;i--){temp_answer.push_back((*this).hugevector[i]);}                                                         
                  }
    }


   HugeInt real_answer;
   for(int i=temp_answer.size()-1;i>=0;i--){
   real_answer.hugevector.push_back(temp_answer[i]);
   }
   
   return real_answer;
    
  }



}; 
