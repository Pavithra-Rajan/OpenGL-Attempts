#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    ofstream file;
    file.open("points.txt");
    srand(time(0));

    for (int i = 0; i < 10; i++) 
    {
 
        file << ((double)rand()) / RAND_MAX;
        file << " "<< ((double)rand()) / RAND_MAX << endl;
    }

    file.close();

    return 0;
}