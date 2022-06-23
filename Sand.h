//sand class

#ifndef SAND_H
#define SAND_H

class Sand{
    
    private:
    int grains; 


    public:
    Sand(){grains=0;}
    Sand(int N);
    ~Sand();
    void Print(void); // prints Sand
    int get_grains(void); //returns number of grains
    void set_grains(int N); //sets number of grains
    void add_grain(void); //adds one grain
    void rem_grain(int zc); //removes zc grains
};

#endif