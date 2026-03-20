#include "../include/InputHelper.h"

#include <cctype>
#include <iostream>
#include <sstream>

namespace 
{
   std::string trim(const std::string& text)
   {
      std::size_t start = text.find_first_not_of(" \t\n\r\f\v");
      if (start == std::string::npos)
      {
         return "";
      }
      
      std::size_t end = text.find_last_not_of(" \t\n\r\f\v");
      return text.substr(start, end-start + 1);
   }
   
   bool tryParseInt(const std::string& text, int& value)
   {
      std::istringstream input(text);

      if (!(input >> value))
      {
         return false;
      }

      input >> std::ws;
      return input.eof();
   }

   bool tryParseFloat(const std::string& text, float& value)
   {
      std::istringstream input(text);

      if (!(input >> value))
      {
         return false;
      }

      input >> std::ws;
      return input.eof();
   }
}

std::string promptRequiredText(const std::string& prompt, const std::string& errorMsg)
{
   std::string input;
   
   while (true)
   {
      std::cout << prompt;
      std::getline(std::cin, input);
      
      input = trim(input);
      if (!input.empty())
      {
         return input;
      }
      
      std::cout << errorMsg << '\n';
   }
}

int promptIntInRange(const std::string& prompt, int minValue, int maxValue, const std::string& errorMsg)
{
   std::string input;
   int value;
   
   while (true)
   {
      std::cout << prompt;
      std::getline(std::cin, input);
      
      input = trim(input);

      if (tryParseInt(input, value) && value >= minValue && value <= maxValue)
      {
         return value;
      }
      
      std::cout << errorMsg << '\n';
   }
}

float promptFloatInRange(const std::string& prompt, float minValue, float maxValue, const std::string& errorMsg)
{
   std::string input;
   float value;

   while (true)
   {
      std::cout << prompt;
      std::getline(std::cin, input);
      
      input = trim(input);
      bool isNegativeText = !input.empty() && input[0] == '-';

      if ((minValue < 0.0f || !isNegativeText) &&
         tryParseFloat(input, value) &&
         value >= minValue &&
         value <= maxValue)
      {
         return value;
      }
      
      std::cout << errorMsg << '\n';
   }
}

char promptGender(const std::string& prompt, const std::string& errorMsg)
{
   std::string input;

   while (true)
   {
      std::cout << prompt;
      std::getline(std::cin, input);

      input = trim(input);

      if (input.size() == 1)
      {
         char gender = static_cast<char>(std::toupper(static_cast<unsigned char>(input[0])));
         if (gender == 'M' || gender == 'F')
         {
            return gender;
         }
      }

      std::cout << errorMsg << '\n';
   }
}
