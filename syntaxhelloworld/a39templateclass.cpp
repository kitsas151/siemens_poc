#include <iostream>
#include <string>

namespace MedicalDomain {

    // Template class for vital signs
    template <typename T,typename Q>
    class VitalSigns {
    private:
        T heartRate_;
        T bloodPressure_;
        T temperature_;

    public:
        VitalSigns(T heartRate, T bloodPressure, T temperature)
            : heartRate_(heartRate), bloodPressure_(bloodPressure), temperature_(temperature) {}

        // Getter methods
        T getHeartRate() const {
            return heartRate_;
        }

        T getBloodPressure() const {
            return bloodPressure_;
        }

        T getTemperature() const {
            return temperature_;
        }

        // Setter methods
        void setHeartRate(T rate) {
            heartRate_ = rate;
        }

        void setBloodPressure(T pressure) {
            bloodPressure_ = pressure;
        }

        void setTemperature(T temp) {
            temperature_ = temp;
        }
    };

}  // End of namespace MedicalDomain

int main() {
    // Example usage of VitalSigns with different data types
    MedicalDomain::VitalSigns<int> patient1(75, 120, 98);  // Integer values
    MedicalDomain::VitalSigns<double> patient2(68.5, 118.5, 98.6);  // Double values

    std::cout << "Patient 1 - Heart Rate: " << patient1.getHeartRate() << std::endl;
    std::cout << "Patient 2 - Temperature: " << patient2.getTemperature() << std::endl;

    return 0;
}
