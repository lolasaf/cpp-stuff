/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:27:49 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/06 10:55:29 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>


BitcoinExchange::BitcoinExchange(): _database() {}

BitcoinExchange::BitcoinExchange(const std::string &databasefilename)
{
    _parseDatabase(databasefilename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::run(const std::string &inputfilename) {
    try {
        _executeInput(inputfilename);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::string BitcoinExchange::_trim(std::string &value) {
    size_t first = value.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        value.clear();
        return value;
    }
    value.erase(0, first);
    size_t last = value.find_last_not_of(" \t\n\r\f\v");
    if (last != std::string::npos)
        value.erase(last + 1);
    return value;
}

double BitcoinExchange::_validatevalue(std::string &value) {
    _trim(value);
    if (value.empty())
        throw std::runtime_error("Error: bad input (empty value)");
    if (value.find_first_not_of("-+0123456789.") != std::string::npos)
        throw std::runtime_error("Error: bad input (invalid value) => " + value);
    // Check for sign: only one sign allowed at the beginning
    bool has_sign = false;
    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == '-' || value[i] == '+') {
            if (i != 0 || has_sign) {
                // Sign not at beginning or multiple signs
                throw std::runtime_error("Error: bad input (invalid value) => " + value);
            }
            has_sign = true;
        }
    }
    // Check for multiple dots
    size_t dot_count = 0;
    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == '.') {
            dot_count++;
            if (dot_count > 1)
                throw std::runtime_error("Error: bad input => " + value);
        }
    }
    char* endptr;
    errno = 0;
    double value_double = std::strtod(value.c_str(), &endptr);
    if (errno == ERANGE)
        throw std::runtime_error("Error: bad input (value out of range): " + value);
    if (endptr == value.c_str() || *endptr != '\0')
        throw std::runtime_error("Error: bad input (invalid value) => " + value);
    if (value_double < 0)
        throw std::runtime_error("Error: not a positive number => " + value);
    return value_double;
}

std::string &BitcoinExchange::_validateDate(std::string &date) {
    _trim(date);
    if (date == "date") return date; // skip header line
    if (date.empty())
        throw std::runtime_error("Error: bad input (empty date)");
    if (date.find_first_not_of("0123456789-") != std::string::npos)
        throw std::runtime_error("Error: bad input (invalid date) => " + date);
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: bad input (invalid date) => " + date);
    // Enforce digits at positions 0-3 (year), 5-6 (month), 8-9 (day)
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
            throw std::runtime_error("Error: bad input (invalid date) => " + date);
    }
    std::stringstream ss(date);
    int year, month, day;
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-' || !ss.eof())
        throw std::runtime_error("Error: bad input (invalid date) => " + date);
    if (year < 0 || month < 1 || month > 12 || day > 31 || day < 1)
        throw std::runtime_error("Error: bad input (invalid date) => " + date);
    if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        throw std::runtime_error("Error: bad input (invalid date) => " + date);
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeapYear))
            throw std::runtime_error("Error: bad input (invalid date) => " + date);
    }
    return date;
}

void BitcoinExchange::_executeInput(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file => " + filename);
    std::string line;
    int line_count = 0;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        line_count++;
        size_t delimiter = line.find('|') != std::string::npos ? line.find('|') : line.find(',');
        if (delimiter == std::string::npos) {
            if (line_count == 1)
                std::cerr << "Error: bad input (header line) => " << line << std::endl;
            else
                std::cerr << "Error: bad input (no delimiter) => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, delimiter);
        try {
            date = _validateDate(date);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
        std::string value = line.substr(delimiter + 1);
        if (date == "date") {
            if (line_count != 1) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            _trim(value);
            if (value != "value")
                std::cerr << "Error: bad input (header line) => " << line << std::endl;
            continue;
        }
        double value_double;
        try {
            value_double = _validatevalue(value);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
        if (value_double > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        // Check if database is empty
        if (_database.empty()) {
            std::cerr << "Error: database is empty" << std::endl;
            continue;
        }
        // Find closest lower date: use upper_bound then decrement
        std::map<std::string, double>::iterator it = _database.upper_bound(date);
        if (it == _database.begin()) {
            // Input date is before all dates in DB - no lower date exists
            std::cerr << "Error: date not found => " << date << std::endl;
            continue;
        }
        --it;  // Go back to get the last date <= input date (closest lower date)
        std::cout << date << " => " << value_double << " = " << it->second * value_double << std::endl;
    }
    if (file.fail() && !file.eof()) {
        throw std::runtime_error("Error: error reading file => " + filename);
    }
}

void BitcoinExchange::_parseDatabase(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file => " + filename);
    std::string line;
    int line_count = 0;
    try {
        while (std::getline(file, line)) {
            if (line.empty())
                continue;
            line_count++;
            size_t comma = line.find(',');
            if (comma == std::string::npos) {
                if (line_count == 1)
                    std::cerr << "Error: bad input (header line) => " << line << std::endl;
                std::cerr << "Error: bad input (no delimiter) => " << line << std::endl;
                continue;
            }
            std::string date = line.substr(0, comma);
            std::string value = line.substr(comma + 1);
            date = _validateDate(date);
            if (date == "date") {
                if (line_count != 1) {
                    std::cerr << "Error: bad input (header line) => " << line << std::endl;
                }
                continue;
            }
            double value_double = _validatevalue(value);
            _database[date] = value_double;
        }
    } catch (const std::exception &e) {
        std::stringstream ss;
        ss << line_count;
        throw std::runtime_error(e.what() + std::string(" at line number ") + ss.str());
    }
    if (file.fail() && !file.eof()) {
        throw std::runtime_error("Error: error reading file => " + filename);
    }
}