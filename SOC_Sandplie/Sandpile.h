//sandpile class
#include "Sand.h" 
#ifndef SANDPILE_H
#define SANDPILE_H

class Sandpile{

    Sand **grid; //2d grid pointer to Sand objects
    int *avalances; //1d matrix to store how big the avalance is
    double *freq; //1d matrix to store the freq of each avalance
    double *freq_t; //1d matrix to store the freq of each avalance

    int N; //dimension of the grid give odd
    int T; // total number of grains added or time steps
    static const int zc=4; //critical value
    
    
    

    //set public functions
    public:  
    Sandpile(int N, int T); //Constructor
    ~Sandpile(); //Deconstructor
    void Initialize(void);// Initiallization to zero all grains
    void thermalization(void); //thermalization of the system
    void add_rn_grain(void); // adds a grain in the sandpile at a random position
    void topple(void); // topples the sand until the configuration is stable
    void run(void); //run the process of adding grains and toppling
    void freq_norm(void); // normalize freq
    double* get_freq(void); //get the freq matrix
    double* get_freqt(void); //get the freq matrix
    int* get_aval(void); //get the aval matrix 
    void Print(void); // prints grid
    void Print_aval(void); //print freq and aval
    

};

#endif