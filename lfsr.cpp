#include <iostream>

using namespace std;

#define SIZE 80

void xorThenBinarayArrayToAscii( int arr[], int size = SIZE) {
 

        int ciphertext[] = {1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,1};
        int tempChar;
        
        for ( int i = 0 ; i < size/8 ; i++ ) {
         
            tempChar = 0;
            
            for ( int j = 0 ; j < 8 ; j++ ) {
                
                    tempChar <<= 1;
                    tempChar ^= ciphertext[8*i+j];
                    tempChar ^= arr[8*i+j];
            }
            
            cout << (char)tempChar;
        }
}       

int main() {
                    
    int LFSR[16] = {1,1,0,0,1,0,1,0,0,1,1,1,0,1,0,1}; //seed
    int output[SIZE];
    
    int nextBit = 0;
    
    cout << "\nkeystream\t: ";
    
    for ( int i = 0; i < SIZE; i++ ) {
     
        nextBit = LFSR[0] ^ LFSR[1] ^ LFSR[3] ^ LFSR[12];
        
        cout << LFSR[0];
        
        output[i]=LFSR[0];
        
        for ( int j = 0; j <15; j++ ) {
            LFSR[j] = LFSR[j+1];
        }
        LFSR[15] = nextBit;
    }
    
    cout << endl << "the pliantext\t: ";
    xorThenBinarayArrayToAscii(output);
    
    cout << endl;
    
    return 0;
}
