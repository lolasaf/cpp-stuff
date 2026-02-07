/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:57:13 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/06 13:57:24 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        int processRPN(const std::string &expression);
        
    private:
        std::stack<int> _operands;

        bool _isOperator(const std::string &token) const;
        bool _isDigit(const std::string &token) const;
        int _performOperation(int a, int b, char op) const;
};

#endif
