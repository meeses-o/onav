#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// Alias Arduino's String type to C++ std::string
using String = std::string;

// Global lookup array referenced inside your function
const char b36_lookup_list[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Your exact function from the .ino file (unmodified)
String translate_b36(int number) {
  int truenum = abs(number);
  if (truenum == 0) return "0";

  String num_base = "";
    
  while (truenum > 0) {
      int remainder = truenum % 36;          
      num_base = b36_lookup_list[remainder] + num_base; 
      truenum /= 36;                            
  }

  if (number < 0) {
    num_base = "-" + num_base;
  }

  return num_base;
}

int main() {
    std::vector<int> test_numbers = {
        0,        // Zero edge case
        10,       // 'A'
        35,       // 'Z'
        36,       // '10'
        100,      // '2S'
        123456,   // Multi-digit
        -36,      // Negative number
        -12345    // Negative multi-digit
    };

    std::cout << "Base-36 Conversion Test Results:\n";
    std::cout << "--------------------------------\n";

    for (int num : test_numbers) {
        std::cout << num << " -> " << translate_b36(num) << "\n";
    }

    return 0;
}