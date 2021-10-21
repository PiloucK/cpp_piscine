/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:37:53 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/21 19:34:34 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:
    MateriaSource( void );
    MateriaSource( const MateriaSource & model );

    virtual ~MateriaSource( void );

    MateriaSource & operator=( const MateriaSource & model );

	void learnMateria( AMateria * );
	AMateria * createMateria( std::string const & type );


protected:

private:
	AMateria *		m_learnedMaterias[4];

};

#endif
