#include <iostream>
#include "Sandpile.h"
#include "random.h"
//#include "Sand.h"

Sandpile::Sandpile(int N, int T){
    this->N=N;
    this->T=T;
    this->grid=new Sand*[N];
    for(int i = 0; i < N; ++i) {
    this->grid[i] = new Sand[N];
    }    

    

    this->avalances=new int[int(N*N)];
    this->freq=new double[int(N*N)];
    this->freq_t=new double[int(N*N)];

    
    //std::cout<<"object created!"<<std::endl;
}

Sandpile::~Sandpile(){
    for(int i = 0; i < this->N; ++i) {
    delete [] this->grid[i];
}
    delete [] this->grid;
    delete [] this->avalances;
    delete [] this->freq;
    delete [] this->freq_t;
    //std::cout<<"object destroyed!"<<std::endl;;
}
//thermalization
void Sandpile::thermalization(void){

    for (int t = 0; t < 10000; t++){
        add_rn_grain();
        topple();

    }

}

//Initiallization of the system together with thermalization
void Sandpile::Initialize(void){  
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
              grid[i][j].set_grains(2);
            

        }
    }

     for(int i=0;i<N*N;i++){
        avalances[i]=0;
        freq[i]=0;
        freq_t[i]=0;
    }
    
     thermalization();
}
//add grain at random
void Sandpile::add_rn_grain(void){
        int x,y;
        x=rand_range(1,N-2);
        y=rand_range(1,N-2);
        grid[x][y].add_grain();
}

//toppling
void Sandpile::topple(void){
    bool crit=true;  
    int s=0,time=0; //counts the number of total topplings and time
    //toplling algorithm
    while(crit){
        
         crit=false;
         for(int i=1;i<N-1;i++){

             for(int j=1;j<N-1;j++){
           
                 if(grid[i][j].get_grains()>=zc){
                    crit=true;
                    
                    grid[i][j].rem_grain(zc);
                    grid[i+1][j].add_grain();
                    grid[i-1][j].add_grain();
                    grid[i][j+1].add_grain();
                    grid[i][j-1].add_grain();
                    
                    s=s+1;

                }
                
                
            }
        
        
        }
   
        //time update
        if(crit==true){time=time+1;};
        
    }

    
    

    if(s!=0){
    avalances[s]=s;
    freq[s]=freq[s]+1;
    freq_t[time]=freq_t[time]+(s/double(time));
    }

    
    
    //boundaries always zero 
    for(int i=0;i<N;i++){
        grid[i][0].set_grains(0);
        grid[i][N-1].set_grains(0);
             
    }

     for(int j=0;j<N;j++){
                 grid[0][j].set_grains(0);
                 grid[N-1][j].set_grains(0);
             }

}


//run function
void Sandpile::run(void){
    for (int t = 0; t < T; t++){
        add_rn_grain();
        topple();

    }
    
}
//normalize freq arrrays
void Sandpile::freq_norm(void){
    int norm=0;
    int norm2=0;
    for (int i = 0; i < N*N; i++){
        norm=norm+freq[i];
        norm2=norm2+freq_t[i];
    }
    for (int i = 0; i < N*N; i++){
        freq[i]=freq[i]/norm;
        freq_t[i]=freq_t[i]/norm2;
    }
    
}
//get freq arrays
double* Sandpile::get_freq(void){
    return freq;
}

double* Sandpile::get_freqt(void){
    return freq_t;
}

int* Sandpile::get_aval(void){
    return avalances;
}
//prints the grid if needed
void Sandpile::Print(void){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j].Print();
        }
        std::cout<<std::endl;
        
    }
    
    
    std::cout<<std::endl;
}

//function to print aval and freq (I do not use it)
void Sandpile::Print_aval(void){

     std::cout<<"aval=[";
    for(int i=0;i<N*N;i++){
        
            std::cout<<avalances[i]<<"  ";
        
        
        
    }
    std::cout<<"]";
    
    std::cout<<std::endl;
    std::cout<<"freq=[";
    for(int i=0;i<N*N;i++){
        
            std::cout<<freq[i]<<"  ";
        
        
        
    }
    std::cout<<"]";
    
    std::cout<<std::endl;
}