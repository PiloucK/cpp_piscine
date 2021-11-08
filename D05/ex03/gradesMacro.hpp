/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradesMacro.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:35:13 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/08 17:24:16 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADESMACRO_HPP
# define GRADESMACRO_HPP

# define GRADE_TOO_HIGH_ERROR_STR "Grade too high\n"
# define GRADE_TOO_LOW_ERROR_STR "Grade too low\n"
# define FORM_NOT_SIGNED_ERROR_STR "Form has to get signed before\n"
# define WORST_GRADE 150
# define BEST_GRADE 1
# define ONE_HIGHER(x) (x - 1)
# define ONE_LOWER(x) (x + 1)

// comparison between grades in macro to keep the confusion of 1 > 2 out of the code
// comp = base number to compare to
// toComp = number you want to test
# define IS_LOWER_GRADE(comp, toComp) (comp < toComp)
# define IS_HIGHER_GRADE(comp, toComp) (comp > toComp)

#endif
