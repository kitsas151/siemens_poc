#if 0

// C++14
#include <iostream>

/*

for basic multilingual plane (BMP), use the escape sequence \\u followed by the hexadecimal 
representation of the character code (e.g., '\\u03C0' represents the Greek alphabet letter pi).

For characters outside the BMP, use \\U followed by the hexadecimal representation of the
 character code (e.g., '\\U0001F600' represents a grinning face).

*/


int main() {
    std::cout << "Unicode: " << '\\u03C0' << '\\n';
    std::cout << "Beyond BMP: " << '\\U0001F600' << '\\n';
    std::cout << "UTF-8: " << u8"\\u03BB" << '\\n';
    return 0;
}




#endif

#if 0


// C++
#include <iostream>
int main() {
    char basicChar = 'a';
    wchar_t wideChar = L'\\u00E9';
    char32_t utf8Char = U'\\u03A9';
    char32_t utf16Char = U'\\U0001F60A';
    char32_t utf32Char = U'\\U0001F609';

    std::cout << "Basic character: " << basicChar << std::endl;
    std::wcout << "Wide character: " << wideChar << std::endl;
    std::cout << "UTF-8 character: " << utf8Char << std::endl;
    std::wcout << "UTF-16 character: " << utf16Char << std::endl;
    std::wcout << "UTF-32 character: " << utf32Char << std::endl;

    return 0;
}


#endif

#if 0

// C++ Program to Handle Unicode Strings

#include <codecvt> //for wstring_convert and codecvt_utf8 if using C++17 or earlier
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main()
{

    // Assuming the source file is saved in UTF-8 encoding
    string utf8_string
        = "Привет, мир!"; // Hello, world! in Russian

    // Convert UTF-8 string to wide string
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t>
        converter;
    wstring wide_string = converter.from_bytes(utf8_string);

    // Print wide string
    wcout.imbue(
        locale("")); // Ensure the wide output stream can
                     // handle the locale properly.
    wcout << L"Wide string: " << wide_string
          << " that means Hello, World! in Russian Language"
          << endl;

    return 0;
}


#endif

#if 0

#include <iostream>

// User-defined literal operator for meters
constexpr long double operator"" _m(long double value) {
    return value; // Simply return the value (interpreted as meters)
}

int main() {
    // Usage of the user-defined literal
    long double distance = 42.5_m; // 42.5 meters

    std::cout << "Distance: " << distance << " meters\n";

    return 0;
}


#endif

#if 0


#include <iostream>

// User-defined literal operator for picoseconds
constexpr long double operator"" _ps(long double value) {
    return value; // Interpret the value as picoseconds
}

int main() {
    // Usage of the user-defined literal
    long double timeInterval = 1000.0_ps; // 1000 picoseconds

    std::cout << "Time interval: " << timeInterval << " ps\n";

    return 0;
}


#endif

/*
Integer Literals:
Integer literals in C++ represent whole numbers without fractional or decimal parts.
Example: 42 (decimal), 0x2A (hexadecimal), 052 (octal).

Floating-Point Literals:
Floating-point literals represent numbers with fractional or decimal parts.
Example: 3.14, 2.5e-3.

Character Literals:
Character literals represent individual characters.
Enclosed in single quotes (e.g., 'A', '7', '%').

Escape sequences for special characters (e.g., '\n' for newline).

String Literals:
String literals represent sequences of characters.
Enclosed in double quotes (e.g., "Hello, World!").

Boolean Literals:
Boolean literals represent truth values (true or false).
Example: true, false.

Pointer Literals:
The nullptr literal represents a null pointer.


*/




#if 1

#include <iostream>
#include <string>

int main() {
    // Store the word "स्वागत" in a variable
    std::string welcomeMessage = "स्वागत";

    // Print the stored message
    std::cout << "Stored message: " << welcomeMessage << std::endl;

    return 0;
}


#endif

