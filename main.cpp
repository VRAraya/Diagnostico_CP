#include <iostream>
#include <ctype.h>

// Función que evalúa si una cadena de caracteres tiene digitos
// Si la cadena es vacía o no contiene números retorna false
bool containsDigits(std::string string)
{
  if (string.length() == 0 || string == " ")
  {
    return false;
  }
  else
  {
    for (int i = 0; i < string.length(); i++)
    {
      if (isdigit(string[i]))
      {
        return true;
      }
      else
      {
        continue;
      }
    }
    return false;
  }
}

// Función que evalúa si una cadena contiene sólo letras.
// Verifica las letras según codigo ASCII: Si los valores ASCII de los caracteres están entre 122 y 97, son letras minusculas.
bool onlyLetters(std::string string)
{
  for (int i = 0; i < string.length(); i++)
  {
    if ((int(string[i]) < 97) || (int(string[i]) > 122))
    {
      return false;
    }
    else
    {
      continue;
    }
  }
  return true;
}

// Función que recibe una cadena, y la devuelve en minuscula
std::string stringToLowerCase(std::string string)
{
  for (int i = 0; i < string.length(); i++)
  {
    string[i] = tolower(string[i]);
  }
  return string;
}

// Función que cuenta la cantidad de veces que se repiten las letras contenidas en una cadena de letras, y devuelve el resultado
std::string countLetters(std::string string)
{
  std::string letter = "", nextLetter = "", result = "";
  int counterLetter = 1;
  for (int i = 0; i < string.length(); i++)
  {
    if (i < string.length())
    {
      letter = string[i];
      nextLetter = string[i + 1];
      if (letter == nextLetter)
      {
        counterLetter++;
      }
      else
      {
        result += string[i] + std::to_string(counterLetter);
        counterLetter = 1;
      }
    }
  }
  return result;
}

// Funcion principal
// Solicita una cadena
// Se encierra en un while, y evalúa que la cadena contenga sólo letras, y no continuará sino se entrega una cadena válida.
// Luego, invoca la función que cuenta las letras de la cadena
// Finalmente imprime el resultado.

int main()
{
  std::string string = "";
  bool exit = false;
  std::cout << "Ingrese una cadena de caracteres: " << std::endl;
  while (!exit)
  {
    std::cin >> string;
    string = stringToLowerCase(string);
    if (containsDigits(string))
    {
      std::cout << "La cadena de caracteres no debe contener numeros. Ingrese una cadena de caracteres: " << std::endl;
      continue;
    }
    else
    {
      if (!onlyLetters(string))
      {
        std::cout << "La cadena de caracteres solo debe contener letras. Ingrese una cadena de caracteres: " << std::endl;
        continue;
      }
      else
      {
        std::string result = "";
        result = countLetters(string);
        std::cout << result << std::endl;
        exit = true;
      }
    }
  }
  return 0;
}