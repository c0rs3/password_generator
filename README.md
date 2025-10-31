# password generator

- C++ password generator via uniform random distribution

- Generator ensures each password has the maximum [bit entropy](#bit-entropy--security) at that password length

## How to Setup

### MinGW Makefiles

- Install MSYS2

```winget install msys2```

- MSYS2 MinGW64 > Install MinGW tools through CLI

```bash
pacman -S --needed base-devel
pacman -S --needed mingw-w64-x86_64-toolchain
```

- Generate build files and build

```bash
cmake -B build -G "MinGW Makefiles"
cmake --build build
```

### Visual Studio Build Tools

- Download & install [C++ Build Tools for Visual Studio 2022](https://aka.ms/vs/17/release/vs_BuildTools.exe)

- Generate build files and build

```bash
cmake -B build -G "Visual Studio 17 2022"
cmake --build build
```

## Bit Entropy & Security

## Usage/Examples

### strengthen_password

- Strengthens the password to maximum possible entropy bits.

```cpp
std::string sample_password2 = "QDMM,MNiaISPxdYi";

strengthen_password(sample_password2);
std::cout << sample_password << std::endl;

/*
* no digit chars present in the password
* function replaces most common char type 
* with an digit, therefore increasing entropy bits
*/
```

### generate_password

- Generates a password with the desired length

```cpp
 std::string sample_password = generate_password(18); // generates a 18-char-password
```

### entropy_bits

- Calculates the entropy bits of given string
`entropy_bits = length * log2(pool_size)` where:
  - pool_size is the unique characters from which we build the password
  - length is the number of chars in the string \
 ([source](https://www.omnicalculator.com/other/password-entropy))

```cpp
std::string sample_password = generate_password(18);

double bits = entropy_bits(sample_password2);

std::cout << "Entropy bits of the generated password: " << bits << " bits" << std::endl;
```

Output:

```bash
117.983 bits 
```

### char_stats

- Returns a vector with the quantities of different char types

```cpp
std::string sample_password = "P@ssw0rd123";

std::vector<uint32_t> stats = char_stats(sample_password);

std::cout << "Char stats of the sample password:" << std::endl;
std::cout << "Uppercase characters: " << stats[0] << std::endl;
std::cout << "Lowercase characters: " << stats[1] << std::endl;
std::cout << "Digits: " << stats[2] << std::endl;
std::cout << "Symbols: " << stats[3] << std::endl;
```

### get_char_type function

```cpp
std::cout << "Char type of 'A': " << get_char_type('A') << ":" << std::endl;

/* upper case -> 0
 *  lower case -> 1
 *  digit -> 2
 *  symbols -> 3  */
```

```cpp
std::string password1 = "Abcde";
std::string password2 = "AaaBbbbCcc";
std::cout << "Does password1 have adjacent duplicates? " << has_adjacent_duplicates(password1) << std::endl;
std::cout << "Does password2 have adjacent duplicates? " << has_adjacent_duplicates(password2) << std::endl;
```

Output:

```bash
Does password1 have adjacent duplicates? 0
Does password2 have adjacent duplicates? 
```

---

```cpp
std::string password3 = "AaaBbbbCcc"; // Password with adjacent duplicates
std::cout << "Password before removing adjacent duplicates: " << password3 << std::endl;
remove_adjacent_duplicates(password3);
std::cout << "Password after removing adjacent duplicates: " << password3 << std::endl;
```

Output:

```bash
Password after removing adjacent duplicates: ABc
Password before removing adjacent duplicates: AaaBbbbCcc
```
