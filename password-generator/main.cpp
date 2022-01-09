/**
 * @file "main.cpp"
 * @version 1.0.0
 * 
 * @copyright (C) 2022 lost-century/~password-generator. all rights reserved
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

// Encabezado personal para determinación de lo que queremos generar.
#include <inc/gen.hpp>

// Crearemos un vector que agarrará la lista de palabras :)
std::vector<std::string> ListaPalabras;

// Lo mismo pero para las keywords :-)
std::vector<std::string> ListaKeywords;

std::string n;

bool CambiaCaracteres = false;
bool AgregarSimbolos = false;
bool CambiarTextoForma = false;

void EscribirArchivo() 
{
    std::ofstream archivoSalida("./listapalabras.txt");
    std::ostream_iterator<std::string> salidaIterador(archivoSalida, "\n");
    std::copy(ListaPalabras.begin(), ListaPalabras.end(), salidaIterador);
    std::cout << "\n Listo!" << std::endl;
}

void GenerarListadoPalabaras() 
{
    for (std::size_t i = 0; i < ListaKeywords.size(); i++)
    {
        for (std::size_t j = 0; j < ListaKeywords.size(); j++)
        {
            if (j == 1 || PalabraEsIgual(ListaKeywords[i], ListaKeywords[j]))
            {
                continue;
            }

            if (AgregarSimbolos)
            {
                if (j == 1 || PalabraEsIgual(ListaKeywords[i], ListaKeywords[j]))
                {
                    continue;
                }
                else
                {
                    std::string Simbolos[] = {
                        "!",
                        "$",
                        "%",
                        "-",
                        ",",
                        "/",
                        "&",
                        "'",
                        "¿",
                        "?",
                        "=",
                        "+",
                        "_",
                        "<",
                        ">",
                        "*",
                        "#"
                    };

                    for (std::size_t k = 0; k < (sizeof(Simbolos) / sizeof(Simbolos[0])); k++)
                    {
                        std::string Temp = ListaKeywords[i] + ListaKeywords[j] + Simbolos[k];
                        ListaPalabras.push_back(Temp);
                    }
                }
            }
            std::string Temp = ListaKeywords[i] + ListaKeywords[j];
            ListaPalabras.push_back(Temp);
        }
    }
    EscribirArchivo();
}

void Resultados(std::vector<std::string> resultado)
{
    for (std::size_t i = 0; i < resultado.size(); i++)
    {
        ListaKeywords.push_back(resultado[i]);
    }

    if (CambiarTextoForma)
    {
        std::size_t KeywordDimension = ListaKeywords.size();

        for (std::size_t i = 0; i < KeywordDimension; i++)
        {
            // Manda para cambiar a texto upper
            std::string Temp = ConvertirTextoUpper(ListaKeywords[i]);
            ListaKeywords.push_back(Temp);

            Temp = ConvertirTextoLower(ListaKeywords[i]);
            ListaKeywords.push_back(Temp);
        }
    }

    if (CambiaCaracteres)
    {
        std::size_t KeywordDimension = ListaKeywords.size();

        for (std::size_t i = 0; i < KeywordDimension; i++)
        {
            std::string Temp = ListaKeywords[i];

            for (std::size_t j = 0; j < Temp.length(); j++)
            {
                if (Temp[j] == 'A' || Temp[j] == 'a')
                {
                    Temp[j] == '4';
                }
                else if (Temp[j] == 'E' || Temp[j] == 'e')
                {
                    Temp[j] == '3';
                }
                else if (Temp[j] == 'I' || Temp[j] == 'i')
                {
                    Temp[j] == '1';
                }
                else if (Temp[j] == 'O' || Temp[j] == 'o')
                {
                    Temp[j] == '0';
                }
                else if (Temp[j] == 'S' || Temp[j] == 's')
                {
                    Temp[j] == '5';
                }
            }
            ListaKeywords.push_back(Temp);
        }
    }
    GenerarListadoPalabaras();
}

void AnalizarString(std::string n)
{
    std::vector<std::string> resultado;
    std::stringstream stringStream(n);

    while (stringStream.good())
    {
        std::string subString;
        std::getline(stringStream, subString, ',');
        resultado.push_back(subString);
    }
    Resultados(resultado);
}

int main()
{
    // TODO: Here.
    return 0;
}