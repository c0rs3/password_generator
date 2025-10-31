#include <iostream>
#include <password_generator.h>

using namespace generator;

std::ostream& operator<<(std::ostream& stream, std::vector<uint32_t> char_stats) {
    stream << "Uppercase characters: " << char_stats[0] << std::endl;
    stream << "Lowercase characters: " << char_stats[1] << std::endl;
    stream << "Digits: " << char_stats[2] << std::endl;
    stream << "Symbols: " << char_stats[3] << std::endl;
    return stream;
}

void benchmark_strength(const size_t& size = 10) {
    std::string generated_password = generator::generate_password(18);
    for (size_t i = 0; i < size; i++) {
        if (entropy_bits(generated_password) == max_entropy(18)) {
            std::cout << "Maximum possible strength password produced|" << size - i << " remaining..." << std::endl;
        }
        else {
            std::cout << "Failed to produce maximum possible strength " << std::endl;
        }
    }
}

void test_strengthen_password(std::string password = "WeakPassword") {
    std::cout << "Original password: " << password << std::endl;

    strengthen_password(password);

    std::cout << "Strengthened password: " << password << std::endl;
}

void test_char_stats(std::string password = "P@ssw0rd123") {
    std::vector<uint32_t> stats = char_stats(password);

    std::cout << "Char stats of the sample password:" << std::endl;
    std::cout << "Uppercase characters: " << stats[0] << std::endl;
    std::cout << "Lowercase characters: " << stats[1] << std::endl;
    std::cout << "Digits: " << stats[2] << std::endl;
    std::cout << "Symbols: " << stats[3] << std::endl;
}
#if 1
int main() {
    std::string sample_string = "Aa1!";
    std::string sample_password1 = generate_password(18); // generates a 18-char-password
    std::string sample_password2 = "QDMM,MNi0ISP7dYi";    // sample password for demonstrating remove_adjacent_duplicate() & has_adjacent_duplicates() functions

    std::cout << "Random integer: " << random_int(0, 10) << std::endl;

    std::cout << "Entropy bits of " << sample_password1 << ":\n"
        << entropy_bits(sample_password1) << " bits" << std::endl;
    std::cout << "Number of tries required to brute force password: " << pow(2, entropy_bits(sample_password1)) << std::endl
        << std::endl;
    std::cout << "Maximum entropy of a 18 character password: " << max_entropy(18) << std::endl
        << std::endl; // returns the maximum possible entropy bits of a 18 char password

    std::cout << "Char type of 'A': " << get_char_type('A') << ":" << std::endl;
    /* upper case -> 0
     *  lower case -> 1
     *  digit -> 2
     *  symbols -> 3 */
    test_char_stats("P@ssw0rd123");

    test_strengthen_password("WeakPassword"); // replace with a weak password

    std::cout << "Example password with duplicates: " << sample_password2 << std::endl;
    std::cout << "Any duplicates? " << std::boolalpha << has_adjacent_duplicates(sample_password2) << std::endl;
    remove_adjacent_duplicates(sample_password2);
    std::cout << "After removing duplicates: " << sample_password2 << std::endl;
    std::cout << "Any duplicates? " << std::boolalpha << has_adjacent_duplicates(sample_password2) << std::endl;

    return 0;
}
#else
#endif