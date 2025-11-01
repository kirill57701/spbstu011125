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

int ** construct(int ** mtx, int init, size_t a, size_t b){
    for (size_t i = 0; i < a; ++i){
        for (size_t j = 0; j < b; ++j){
            mtx[i][j] = init;
        }
    }
    return mtx;
}

void input(int** mtx, size_t a, size_t b){
    for (size_t i = 0; i < a; ++i){
        for (size_t j = 0; j < b; ++j){
            std::cin >> mtx[i][j];
        }
    }
}

void output(int ** m, size_t a, size_t b){
    for (size_t i = 0; i < a; ++i){
        for (size_t j = 0; j < b; ++j){
            if (j < b - 1){
                std::cout << m[i][j] << " ";
            }
            else{
                std::cout << m[i][j] << "\n";
            }
        }
    }
}

int main(){
    size_t a, b;
    std::cin >> a >> b;
    if (!std::cin){
        return 2;
    }
    int ** matrix = nullptr;
    try {
        matrix = create(a, b);
    }
    catch(const std::bad_alloc & e){
        std::cerr << e.what();
        return 1;
    }
    int c;
    std::cin >> c;
    matrix = construct(matrix, c, a, b);
    input(matrix, a, b);
    if (!std::cin){
        std::cerr << "input error\n";
        return 1;
    }
    output(matrix, a, b);
    destroy(matrix, 4);
}
