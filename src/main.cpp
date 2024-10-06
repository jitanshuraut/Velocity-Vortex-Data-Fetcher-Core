#include "DataFetcher.hpp"
#include "Bar.hpp"
#include "Quote.hpp"
#include "Trade.hpp"
#include <iostream>

int main() {
    DataFetcher fetcher;

    std::string jsonResponseBars = fetcher.getHistoricalBars("AAPL", "1Day", "2024-01-01", "2024-01-31");
    std::cout << jsonResponseBars << std::endl;
    std::vector<Bar> bars = fetcher.parseHistoricalBars(jsonResponseBars, "AAPL");

    for (const auto& bar : bars) {
        bar.print();
    }

    std::string jsonResponseLatestBars = fetcher.getLatestBars("AAPL");
    Bar latestBar = fetcher.parseLatestBars(jsonResponseLatestBars,"AAPL");
    latestBar.print();

    std::string jsonResponseQuotes = fetcher.getHistoricalQuotes("AAPL", "2024-01-01", "2024-01-03");
    std::cout << jsonResponseQuotes << std::endl;
    std::vector<Quote> quotes = fetcher.parseHistoricalQuotes(jsonResponseQuotes, "AAPL");

    for (const auto& quote : quotes) {
        quote.print();
    }

    std::string jsonResponseTrades = fetcher.getHistoricalTrades("AAPL", "2024-01-01", "2024-01-03");
    std::cout << jsonResponseTrades << std::endl;
    std::vector<Trade> trades = fetcher.parseHistoricalTrades(jsonResponseTrades, "AAPL");

    for (const auto& trade : trades) {
        trade.print();
    }

    return 0;
}
