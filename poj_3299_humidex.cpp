#include <iostream>
#include <cmath>
using namespace std;

const double E = 2.718281828;

int main() {
    while (true) {
        char c1, c2;
        double value1, value2;
        cin >> c1;
        if (c1 == 'E') { break; }
        cin >> value1 >> c2 >> value2;

        double temperature = 0.0, dewpoint = 0.0, humidex = 0.0, e, h;
        if ((c1 == 'T' && c2 == 'D') or (c1 == 'D' && c2 == 'T')) {
            if (c1 == 'T') {
                temperature = value1;
                dewpoint = value2;
            }
            else {
                temperature = value2;
                dewpoint = value1;
            }
            e = 6.11 * pow(E, 5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
            h = (0.5555) * (e - 10.0);
            humidex = temperature + h;
        }
        else if ((c1 == 'T' && c2 == 'H') or (c1 == 'H' && c2 == 'T')) {
            if (c1 == 'T') {
                temperature = value1;
                humidex = value2;
            }
            else {
                temperature = value2;
                humidex = value1;
            }
            h = humidex - temperature;
            e = h / 0.5555 + 10;
            dewpoint = 1 / ((1 / 273.16) - (log(e / 6.11) / log(E)) / 5417.7530) - 273.16;
        }
        else if ((c1 == 'D' && c2 == 'H') or (c1 == 'H' && c2 == 'D')) {
            if (c1 == 'D') {
                dewpoint = value1;
                humidex = value2;
            }
            else {
                dewpoint = value2;
                humidex = value1;
            }
            e = 6.11 * pow(E, 5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
            h = (0.5555) * (e - 10.0);
            temperature = humidex - h;
        }
        printf("%c %.1lf %c %.1lf %c %.1lf\n", 'T', temperature, 'D', dewpoint, 'H', humidex);
    }
    return 0;
}