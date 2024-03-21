// Heo, Isidor

#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

// We already obtained AU in watts per kelvin, which would be in watts upon multiplying by the temperature for each hour data-point later. To scale this to megawatt-hour, simply multiply by 10^(-6) and multiply by 3600.
const double AU = 11119.4725 * 1e-6 * 3600;
unsigned long cnt = 0;
double net_energy = 0.0;
int main()
{
    // use the following to know the maximum limit of double for your compiler
    // cout << numeric_limits<double>::max() << endl;
    
    // we are scanning line 2 to line 8761
    // cout << "The following are the amounts of required heat energies for each hour that needs heating, in Megawatt-hours." << endl;
    for (int i=1; i<=8761; i++) {
        if (i == 1) {
            // this is the first line, so throw it away
            string dummy;
            getline(cin, dummy);
            continue;
        }
        double hour, temperature;
        scanf("%lf;%lf", &hour, &temperature);
        // check if this hour needs heating
        if (temperature >= 15.0) {
            // already balanced, so skip
            continue;
        }
        // compute and define the temperature difference (delta T), then convert it to Kelvin so that it can be multiplied with C (to cancel out the Kelvins in computing Q)
        double temperature_difference = 15.0 - temperature + 273.15;
        // once the temperature difference is calculated, accordingly calculate the amount of heat needed to raise the current temperature to 15 degrees Celsius
        double E = AU * temperature_difference;
        // [E] = MWh

        // add it to the variable responsible for the total amount of heat needed (over the course of the year)
        net_energy += E;
        
        // count this hour that has been needed for heating
        cnt++;
    }

    cout << "5.3 \n" << endl;
    cout << "Average hourly heat demand: " << net_energy / cnt << " MWh." << endl;
    
    // cout << "There were a total of " << cnt << " number of hours within 8760 hours of the year that were in need of balancing (due to being below 15 degrees Celsius)." << endl;

    cout << "\n5.4 \n" << endl;
    cout << "Total: " << setprecision(3) << net_energy << " MWh." << endl;
    // since the price is $150 per MWh, simply multiply the total by it, then divide it by three.
    cout << "Electricity bill: $" << setprecision(3) << net_energy * 150 / 3  << '.' << endl;

    return 0;
}

