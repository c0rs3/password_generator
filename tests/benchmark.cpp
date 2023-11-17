#include <iostream>
#include "..\password_generator.hpp"

using namespace generator;

void benchmark_strength(const size_t& size = 10){
    std::string generated_password = generator::generate_password(18);
    for (size_t i = 0; i < size; i++) {
        if (entropy_bits(generated_password) == max_entropy(18)) {
            std::cout << "Maximum possible strength password produced" << std::endl;
        } else {
            std::cout << "Failed to produce maximum possible strength " << std::endl;
        }
    }   
}

int main() { 
    benchmark_strength(1000);   
    return 0;
}
