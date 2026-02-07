/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:27:52 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/05 18:28:48 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &databasefilename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        void run(const std::string &inputfilename);
        
    private:
        std::map<std::string, double> _database;
        
        void _executeInput(const std::string &filename);
        void _parseDatabase(const std::string &filename);
        std::string _trim(std::string &value);
        double _validatevalue(std::string &value);
        std::string &_validateDate(std::string &date);
};

#endif