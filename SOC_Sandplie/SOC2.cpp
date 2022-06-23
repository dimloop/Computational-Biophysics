/*****************************************************************************
* Computational Biophysics
*  
* SOC model
*
* Name: Dimitrios Loupas AEM :4387

*****************************************************************************/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Sand.h"
#include "Sandpile.h"


//function prototypes
void write(int N, double *array,const char *name);
void write(int N, int *array,const char *name);



int main(int argc, char **argv){


    int N, samples;

    if(argc==1){
        std::cout<<"Program runs with default values N=50 and samples=200"<<std::endl;
        N=50;
        samples=200; //number of samples
    }
    if(argc>=2)
    {
        
        N=atoi(argv[1]);
        samples=atoi(argv[2]);
        std::cout<<"Program runs with N= "<<N<<" and samples= "<<"samples"<<std::endl;

    }



     time_t t;
    // Intializes random number generator 
    
    srand((unsigned) time(&t));
    
    //initiallization of variables and matrices
    double* f, *ft;
    int* aval; 
    int* times;
    double* freq_av;
    double* freq_avt;
    freq_av=new double[N*N];
    freq_avt=new double[N*N];
    aval=new int[N*N];
    times=new int[N*N];

    for (int i = 0; i < N*N; i++){
        freq_av[i]=0;
        freq_avt[i]=0;
        aval[i]=i;
        times[i]=i;
        
    }

        Sandpile obj(N,2000);

    
    //averaged over 200 samples
    for (int i = 0; i < samples; i++){
        obj.Initialize();
        obj.run();
        obj.freq_norm();
        f=obj.get_freq();
        ft=obj.get_freqt();
        for (int j = 0; j < N*N; j++){
            freq_av[j]=freq_av[j]+f[j];
            freq_avt[j]=freq_avt[j]+ft[j];
             
        }
        std::cout.flush();
        std::cout<<"progression: "<<double(100*i/samples)<<" %\r";
        
    }

    for (int j = 0; j < N*N; j++){
            freq_av[j]=freq_av[j]/samples;
            freq_avt[j]=freq_avt[j]/samples;
             
        }
    
    

    //string definitions to write to a file
    std::string f_av="freq.txt";
    std::string av="aval.txt";
    std::string f_avt="freq_t.txt";
    std::string time="t.txt";
    
    //write to file
    write(N*N,freq_av,f_av.c_str());
    write(N*N,freq_avt,f_avt.c_str());
    write(N*N,aval,av.c_str());
    write(N*N,times,time.c_str());
}


//function to write to a file a double array
void write(int N, double *array,const char *name){
    std::ofstream MyFile(name);

   for(int i=1;i<N;i++){
        MyFile <<array[i]<<" ";
    }

  

}
//function to write to a file an int array
void write(int N, int *array,const char *name){
    std::ofstream MyFile(name);

   for(int i=1;i<N;i++){
        MyFile <<array[i]<<" ";
    }

  

}