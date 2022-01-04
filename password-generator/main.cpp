/**
 * @file "main.cpp"
 * @version 1.0.0
 * 
 * @copyright (C) 2021 lost-century/~password-generator. all rights reserved
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

// Encabezado personal para determinación de lo que queremos generar.
#include "gen.hpp"

// Crearemos un vector que agarrará la lista de palabras :)
std::vector<std::string> ListaPalabras;

// Lo mismo pero para las keywords :-)
std::vector<std::string> ListaKeywords;

std::string n;