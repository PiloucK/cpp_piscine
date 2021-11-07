/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:49:28 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/04 14:45:42 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {
	
public:
	virtual ~IMateriaSource( void ) {};

	virtual void learnMateria( AMateria * m ) = 0;
	virtual AMateria * createMateria( std::string const & type ) = 0;

protected:

private:

};

#endif
