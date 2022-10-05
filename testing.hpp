/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:18:18 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 10:32:50 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_HPP
#define TESTING_HPP
#include "test_utils.cpp"
#include <sys/time.h>
typedef struct timeval	t_timeval;

template<typename T>
void compareVectors(std::vector<T> v, std::vector<T> v2);
int	gettime(t_timeval start);
#endif