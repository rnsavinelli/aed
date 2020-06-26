/* ex_11.cpp
 *
 * Se carga un vector con 8 elementos enteros. Estos valores representan el
 * puntaje obtenido en un campeonato por los equipos que participan. En la
 * posición de subíndice i se encuentra el puntaje del equipo al que se dio
 * el código i. Informe la tabla de posiciones, ordenando de mayor a menor
 * puntaje, e indicando a que equipo corresponde ese puntaje.
 *
 * Cargue en un vector de strings los nombres de los equipos.
 * Modifique para que la tabla de posiciones de muestre con el nombre del
 * equipo en lugar del código numérico.
 *
 * Copyright (c) 2020 Savinelli Roberto Nicolás <rsavinelli@est.frba.utn.edu.ar>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <iostream>
#include <cassert>

#define N_DEBUG     1

#define TEAMS { "Estudiantes de La Plata", "Nueva chicago", "Almagro", "Temperley", "Banfield", "Tucumán", "San Lorenzo", "Vélez" }
#define N_TEAMS 8

using namespace std;

void data_prompt(unsigned int scores[], string names[], unsigned const int size)
{
    assert(scores);
    assert(names);

    for(unsigned int i = 0; i < size; i++) {
        cout << names[i] << ": ";
        cin >> scores[i];
    }
}

void data_print(unsigned int scores[], string names[], unsigned const int size)
{
    assert(scores);
    assert(names);

    for(unsigned int i = 0; i < size; i++) {
        cout << i+1 << "- " << names[i] << " scoring " << scores[i] << endl;
    }
}

void
insertionSort(unsigned int scores[], string names[], unsigned const int size)
{
    assert(scores);
    assert(names);

    unsigned int i = 1;

    while(i < size) {
        unsigned int j = i;

        while(j > 0 && scores[j-1] < scores[j]) {
            swap(scores[j], scores[j-1]);
            swap(names[j], names[j-1]);
            j--;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    unsigned int team_scores[N_TEAMS] {};
    string team_names[N_TEAMS] = TEAMS;

    cout << ":: There are " << N_TEAMS
         << " teams participating in the tournament."
         << endl << "What is their score?" << endl;

    data_prompt(team_scores, team_names, N_TEAMS);

    insertionSort(team_scores, team_names, N_TEAMS);
    cout << endl << ":: Leaderboard:" << endl;
    data_print(team_scores, team_names, N_TEAMS);

    return 0;
}
