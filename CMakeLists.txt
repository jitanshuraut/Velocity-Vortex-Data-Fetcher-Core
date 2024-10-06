cmake_minimum_required(VERSION 3.10)
project(StockDataFetcher)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

find_package(CURL REQUIRED)
find_package(jsoncpp REQUIRED)

set(SOURCES
    src/DataFetcher.cpp  
    src/main.cpp         
)

add_executable(StockDataFetcher ${SOURCES})

target_link_libraries(StockDataFetcher PRIVATE CURL::libcurl jsoncpp_lib)