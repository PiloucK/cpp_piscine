#!/bin/bash

DIALOG_H="30"
DIALOG_W="80"
MENU_LIST_H="15"

CHOICES_F=".cppScript.choices"
LIST_TOCREATE_F=".cppScript.tocreate"
LIST_CREATED_F=".cppScript.created"
BACKUP_D=".cppScript.backup"

clean_exit() {
    rm -rf $CHOICES_F $LIST_CREATED_F $LIST_TOCREATE_F
    exit
}

main_menu () {
    whiptail --title "Custom cpp file creation (big shout-out to 42)" \
        --menu "\nWould you like to\n" \
        $DIALOG_H $DIALOG_W $MENU_LIST_H \
    "Class -->" "Create both .cpp and .hpp files for a brand new canonical class." \
    "Cpp   -->" "Create only a .cpp file." \
    "Hpp   -->" "Create only a .hpp file." \
    "Back  <--" "Return to the main menu." \
    "Exit  ..." "Exit from the script." 2>.cppScript.choices
}

cpp_create() {
    whiptail --inputbox "Name the file" $DIALOG_H $DIALOG_W "example.cpp" 2>.cppScript.tocreate

    if [[ "$?" == "0" ]]; then
        FILE_NAME=$(cat .cppScript.tocreate).cpp

        if ls | grep -qx "$FILE_NAME"; then
            whiptail --yesno "The file named $FILE_NAME currently exists and would get overwritten\
                \n\nAre you sure?" $DIALOG_H $DIALOG_W $MENU_LIST_H
            if [ $? ]; then
                clean_exit
            fi
        else
            whiptail --yesno "Do you confirm the file name $FILE_NAME?" \
                $DIALOG_H $DIALOG_W $MENU_LIST_H
            if [ $? == 1 ]; then
                echo toto
                exit
            else
                exit
            fi
        fi
    fi
}

main() {

    while true
    do
        main_menu

        if grep -q "Exit" .cppScript.choices; then
            clean_exit
        elif grep -q "Cpp" .cppScript.choices; then
            cpp_create || continue
        # elif grep -q "Back" .cppScript.choices; then
        #     main_menu
        else
            clean_exit
        fi
    done

    exit
}

main
