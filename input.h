#ifndef __INPUT_H_
#define __INPUT_H_

#include <chrono>
#include <string>
#include <vector>

struct Input {
    std::chrono::year_month_day min_start_date; // Minimal allowed trip start date
    std::chrono::year_month_day max_end_date; // Maximal allowed trip end date
    int max_duration; // Maximal allowed trip duration
    std::string origin; // Origin airport code
    double max_layover; // Maximal allowed layover in hours, could be 0 for direct flights only
    struct city {
        std::string name; // Displayable city name
        std::string code; // Airport code
        int min_days; // Minimal days to spend in the city, 0 if visit of this city is not necessary
        int night_price; // Price per night for optimal calculation. If 0, all unnecessary cities will be skipped.
        std::vector<std::chrono::year_month_day> must_dates; // Dates to spend in this city obligatorily
        std::vector<std::chrono::weekday> must_days; // Weekdays to spend in this city obligatorily
    };
    std::vector<city> cities; // List of cities in chronological visit order
};

// TODO: Replace with config reading
static inline Input GetInput() {
    using namespace std::literals;
    Input input;
    input.min_start_date = std::chrono::year_month_day(2025y, std::chrono::November, 13d);
    input.max_end_date = std::chrono::year_month_day(2025y, std::chrono::December, 7d);
    input.max_duration = 9;
    input.origin = "TLV";
    input.max_layover = 0.0;
    input.cities.push_back({"Berlin", "BER", 3, {}, {std::chrono::Friday, std::chrono::Saturday}});
    input.cities.push_back({"Belgrade", "BEG", 3, {}, {std::chrono::Friday}});
    return input;
}

struct flight {
    ///
};

static inline flight GetChepestFlight() {
    return {};
}

#endif /* __INPUT_H_ */