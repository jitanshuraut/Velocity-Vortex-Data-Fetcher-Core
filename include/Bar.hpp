#ifndef BAR_HPP
#define BAR_HPP

#include <json/json.h> 
#include <iostream>

class Bar {
public:
    std::string time;
    std::string symbol; 
    double open;
    double high;
    double low;
    double close;
    long volume;


Bar(std::string sys):symbol{sys}{}
  void fromJson(const Json::Value& json) {
    time = json["t"].asString();
    open = json["o"].asDouble();
    high = json["h"].asDouble();
    low = json["l"].asDouble();
    close = json["c"].asDouble();
    volume = json["v"].asInt64();
}

    void print() const {
        std::cout << "Time: " << time
                  << ", Open: " << open
                  << ", High: " << high
                  << ", Low: " << low
                  << ", Close: " << close
                  << ", Volume: " << volume << std::endl;
    }
};

#endif 
