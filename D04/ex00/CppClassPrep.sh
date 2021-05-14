#!/bin/bash

eval `resize`

CHOICE_SAVING_FILE=".cppScript.choices"

echo $COLUMNS $LINES

# "Full init" "Complete project creation (folder + makefile + class init)" \ __TODO
main_menu () {
    whiptail --title "Custom cpp file creation (big shout-out to 42)" \
        --menu "\nWould you like to\n" \
        $(( 30 )) $(( 80 )) $(( 15 )) \
    "Class -->" "Create both .cpp and .hpp files for a brand new canonical class." \
    "Cpp   -->" "Create only a .cpp file." \
    "Hpp   -->" "Create only a .hpp file." \
    "Back  <--" "Return to the main menu." \
    "Exit  ..." "Exit from the script." 2>.cppScript.choices
}

main() {

    while true
    do
        main_menu
        exit
    done

}

main
