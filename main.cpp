#include <iostream>

int i=0;
int w;
int v[30];
int Key[30];
int n,x,c,a;

void D_A(){//解仿射密碼
        for(int j=0;j<i;j++){
        n=0;
        
        if(v[j]==((int)'_')-65){ 

                w=(int)' ';
                std::cout<<(char)w;
        }
        else{
                while((v[j]-c+(n*26))%a ){
                        
                        n++;
                }
                w=((v[j]-c+(n*26))/a)+65;
                       std::cout<<(char)w;         
                }

        }

        

}
void E_A(){//以仿射密碼加密
        
        for(int j=0;j<i;j++){
                if(v[j]==((int)'_')-65){ 

                        w=(int)' ';
                        std::cout<<(char)w;
        }
        else{
                w=(v[j]*a+c)%26+ 65;
                std::cout<<(char)w;
        }
        }
        
}
void E_Vig(int Key_i){//維吉尼爾加密

        int z=0;

        for(int j=0;j<i;j++){
        
                if(v[j]==((int)'_')-65){ 
                        z++;
                        w=(int)' ';
                        std::cout<<(char)w;
        }else{
                w= (v[j] + Key[(j-z)%Key_i]+26)%26 + 65;
                std::cout<<(char)w;
        }
        }
}
void D_Vig(int Key_i){//維吉尼爾解密

        int z=0;

        for(int j=0;j<i;j++){
        
                if(v[j]==((int)'_')-65){ 
                        z++;
                        w=(int)' ';
                        std::cout<<(char)w;
        }else{//+26防止出現小於'A'的值
                w= (v[j] - Key[(j-z)%Key_i]+26)%26 + 65;
                std::cout<<(char)w;
        }
        }
}



int main() {
        int mod[3];
        std::cout<<"仿射請打0;維吉尼爾請打1";
        std::cin>>mod[0];
        std::cout<<"解密請打0;加密請打1";
        std::cin>>mod[1];
        


        char V;
        std::cout<<"輸入你要";
        mod[1]? std::cout<<"加密" : std::cout<<"解密" ;
        std::cout<<"的文字(要結束請輸入@)\n";
        std::cin>>V;
        //std::cout<<(int)V;

//輸入內容，當是@停止
while(V != '@' ){
        
        v[i]=(int)V-65;
        //std::cout<<v[i]<<"\n"; 
        i++;
        std::cin>>V;
            
}
        
        if(!mod[0]){
                std::cout<<"輸入兩個係數\n";
                 std::cin>>a>>c ;
                mod[1]? E_A() : D_A();
        }else{        
              
        std::cout<<"輸入金鑰長度";
        std::cin>>n;
        std::cout<<"輸入金鑰種類\"數字0\",\"字母1\"";
        std::cin>>mod[2];
        std::cout<<"輸入金鑰";
        int j=0;
        int Vi;
        while(n){
                if(mod[2]){

                        std::cin>>V;
                        Key[j]=(int)V-65;
                }else{
                       
                        std::cin>>Vi;
                        Key[j]=Vi-1;
                }
                        
                
                
                j++;
                n--;
        }
        mod[1]?E_Vig(j):D_Vig(j);
                
                
        }

}
  
