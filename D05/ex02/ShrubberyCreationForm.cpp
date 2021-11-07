/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:27:56 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/31 18:31:05 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(
	const std::string target )
		: Form("shrubbery creation", 145, 137)
		, m_Target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm & model )
		: Form(model.getName(), model.getSignGrade(), model.getExecGrade(), model.getIsSigned())
		, m_Target(model.m_Target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm & model )
{
	Form::operator=(model);
	m_Target = model.m_Target;
	
	return *this;
}

void
ShrubberyCreationForm::doAction(
	void ) const
{
	std::ofstream outFile(m_Target + "_shrubbery");
	
	outFile << ""
"        / / /                                             / / /                                             / / /                                             / / /                                             / / /                                     \n"
"       /        /  /     //    /                         /        /  /     //    /                         /        /  /     //    /                         /        /  /     //    /                         /        /  /     //    /                  \n"
"    /                 /         /  /                  /                 /         /  /                  /                 /         /  /                  /                 /         /  /                  /                 /         /  /              \n"
"                    /                                                 /                                                 /                                                 /                                                 /                             \n"
"   /               /                //               /               /                //               /               /                //               /               /                //               /               /                //            \n"
"   /          /            /              /          /          /            /              /          /          /            /              /          /          /            /              /          /          /            /              /       \n"
"  /            '/,        /               /         /            '/,        /               /         /            '/,        /               /         /            '/,        /               /         /            '/,        /               /       \n"
"   /              'b      *                          /              'b      *                          /              'b      *                          /              'b      *                          /              'b      *                       \n"
"    /              '$    //                //         /              '$    //                //         /              '$    //                //         /              '$    //                //         /              '$    //                //     \n"
"  /    /           $:   /:               /          /    /           $:   /:               /          /    /           $:   /:               /          /    /           $:   /:               /          /    /           $:   /:               /        \n"
" //      /  //      */  @):        /   / /         //      /  //      */  @):        /   / /         //      /  //      */  @):        /   / /         //      /  //      */  @):        /   / /         //      /  //      */  @):        /   / /        \n"
"             /     :@,@):   ,/**:'   /                         /     :@,@):   ,/**:'   /                         /     :@,@):   ,/**:'   /                         /     :@,@):   ,/**:'   /                         /     :@,@):   ,/**:'   /            \n"
"  /      /,         :@@*: //**'      /   /          /      /,         :@@*: //**'      /   /          /      /,         :@@*: //**'      /   /          /      /,         :@@*: //**'      /   /          /      /,         :@@*: //**'      /   /        \n"
"           '/o/    /:(@'/@*\"'  /                            '/o/    /:(@'/@*\"'  /                            '/o/    /:(@'/@*\"'  /                            '/o/    /:(@'/@*\"'  /                            '/o/    /:(@'/@*\"'  /                  \n"
"   /  /       'bq,/|:,@@*'   ,*      /  /            /  /       'bq,/|:,@@*'   ,*      /  /            /  /       'bq,/|:,@@*'   ,*      /  /            /  /       'bq,/|:,@@*'   ,*      /  /            /  /       'bq,/|:,@@*'   ,*      /  /         \n"
"              ,p$q8,:@)'  /p*'      /                           ,p$q8,:@)'  /p*'      /                           ,p$q8,:@)'  /p*'      /                           ,p$q8,:@)'  /p*'      /                           ,p$q8,:@)'  /p*'      /             \n"
"       /     '  / '@@Pp@@*'    /  /                      /     '  / '@@Pp@@*'    /  /                      /     '  / '@@Pp@@*'    /  /                      /     '  / '@@Pp@@*'    /  /                      /     '  / '@@Pp@@*'    /  /               \n"
"        /  / j/    Y7'.'     /  /                         /  / j/    Y7'.'     /  /                         /  / j/    Y7'.'     /  /                         /  / j/    Y7'.'     /  /                         /  / j/    Y7'.'     /  /                 \n"
"                  :@):.                                             :@):.                                             :@):.                                             :@):.                                             :@):.                           \n"
"                 .:@:'.                                            .:@:'.                                            .:@:'.                                            .:@:'.                                            .:@:'.                           \n"
"               .::(@:.                                           .::(@:.                                           .::(@:.                                           .::(@:.                                           .::(@:.                            \n";

	outFile.close();
}
