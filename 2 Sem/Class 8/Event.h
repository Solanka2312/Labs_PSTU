#pragma once
#pragma once

const int evNothing = 0;   
const int evMessage = 100; 

const int cmMake = 1;    
const int cmAdd = 2; 
const int cmDel = 3;  
const int cmShow = 4;  
const int cmGet = 5;    
const int cmQuit = 101;    

struct TEvent
{
    int what;       
    union
    {
        int command;
        struct
        {
            int message;
            int a; 
        };
    };
};
