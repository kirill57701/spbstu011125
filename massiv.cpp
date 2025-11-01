#include <iostream>
#include <cstddef>

void destroy(int ** mtx, size_t cr){
    for (size_t i = 0; i < cr; ++i){
        delete[] mtx[i];
    }
    delete[] mtx;
}

int ** create (size_t a, size_t b){
    size_t cr = 0;
    int ** mtx = new int * [a];
    try{
        for (; cr < a; ++cr){
            mtx[cr] = new int[b];
        }
    }
    catch (const std::bad_alloc& e){
        destroy(mtx, cr);
        throw;
    }
    return mtx;
}

int main(){
    int ** matrix = nullptr;
    try {
        matrix = create(5, 5);
    }
    catch(const std::bad_alloc & e){
        std::cerr << e.what();
        return 1;
    }
    destroy(matrix, 8);
}
