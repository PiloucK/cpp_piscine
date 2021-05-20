#!/bin/sh

DIALOG_H="30"
DIALOG_W="80"
MENU_LIST_H="15"

INPUT_F=".cppScript.input"
LIST_TOCREATE_F=".cppScript.tocreate"
LIST_CREATED_F=".cppScript.created"
BACKUP_D=".cppScript.backup"

clean_exit() {
    rm -rf $INPUT_F $LIST_TOCREATE_F $LIST_CREATED_F
    exit
}

backup_exit() {
    rm -rf $(cat $LIST_CREATED_F)
    mv $BACKUP_D/* .
    rm -rf $INPUT_F $LIST_TOCREATE_F $LIST_CREATED_F $BACKUP_D
    exit
}

main_menu () {
    whiptail --title "Custom cpp file creation (big shout-out to 42)" \
        --menu "\nWould you like to\n" \
        $DIALOG_H $DIALOG_W $MENU_LIST_H \
    "Class -->" "Create both .cpp and .hpp files for a brand new canonical class." \
    "Cpp   -->" "Create only a .cpp file." \
    "Hpp   -->" "Create only a .hpp file." \
    "Cancel !!" "Backup all changes." \
    "Back  <--" "Return to the main menu." \
    "Exit  ..." "Exit from the script." 2>.cppScript.input
}

cpp_create() {
    whiptail --inputbox "Name the file" $DIALOG_H $DIALOG_W "example.cpp" 2>.cppScript.tocreate

    if [ $(cat .cppScript.tocreate) ]; then
        FILE_NAME=$(cat .cppScript.tocreate)

        if ls | grep -qx "$FILE_NAME"; then
            whiptail --yesno "The file named $FILE_NAME currently exists and would get overwritten\
                \n\nAre you sure?" $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                true
            else
                return
            fi
        else
            whiptail --yesno "Do you confirm the file name $FILE_NAME?" \
                $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                true
            else
                cpp_create
            fi
        fi

        mv $FILE_NAME "$BACKUP_D/$FILE_NAME"
        touch $FILE_NAME

        while true; do
            whiptail --cancel-button "Next" --inputbox "Name headers you want to include one by one" $DIALOG_H $DIALOG_W "<>" 2>.cppScript.input

            if [ $? = 0 ]; then
                echo "#include $(cat .cppScript.input)" >> $FILE_NAME
            else
                break
            fi
        done

        echo >> $FILE_NAME

        whiptail --cancel-button "Next" --inputbox "What is the return type of the function?" $DIALOG_H $DIALOG_W "void" 2>.cppScript.input
        echo "$(cat .cppScript.input)" >> $FILE_NAME

        whiptail --cancel-button "Next" --inputbox "What is the name of the function?" $DIALOG_H $DIALOG_W "main" 2>.cppScript.input
        echo "$(cat .cppScript.input)(" >> $FILE_NAME

        whiptail --cancel-button "Next" --inputbox "Type the first parameter" "void" $DIALOG_H $DIALOG_W 2>.cppScript.input
        echo -n "\t$(cat .cppScript.input)" >> $FILE_NAME

        while true; do
            whiptail --cancel-button "Next" --inputbox "Type any additional parameter" $DIALOG_H $DIALOG_W 2>.cppScript.input

            if [ $? = 0 ]; then
                echo -n "\n\t, $(cat .cppScript.input)" >> $FILE_NAME
            else
                break
            fi
        done

        whiptail --yesno "Would you like to make it a const function?" $DIALOG_H $DIALOG_W

        if [ $? = 0 ]; then
            echo " ) const\n{\n}" >> $FILE_NAME
        else
            echo " )\n{\n}" >> $FILE_NAME
        fi

        whiptail --yesno "Are you satisfied with the created file?" \
            $DIALOG_H $DIALOG_W $MENU_LIST_H
        if [ $? = 0 ]; then
            echo $FILE_NAME >> .cppScript.created
        else
            rm -rf $FILE_NAME
            cpp_create
        fi
    fi
}

hpp_create() {
    whiptail --inputbox "Name the file" $DIALOG_H $DIALOG_W "example.hpp" 2>.cppScript.tocreate

    if [ $(cat .cppScript.tocreate) ]; then
        FILE_NAME=$(cat .cppScript.tocreate)

        if ls | grep -qx "$FILE_NAME"; then
            whiptail --yesno "The file named $FILE_NAME currently exists and would get overwritten\
                \n\nAre you sure?" $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                mv $FILE_NAME "$BACKUP_D/$FILE_NAME"
                true
            else
                return
            fi
        else
            whiptail --yesno "Do you confirm the file name $FILE_NAME?" \
                $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                true
            else
                cpp_create
            fi
        fi

        touch $FILE_NAME

        sed -iE "s/\./_/g" .cppScript.tocreate
        echo -n "#ifndef " > $FILE_NAME
        cat .cppScript.tocreate | awk '{ print toupper ($0) }' >> $FILE_NAME
        echo -n "# define " >> $FILE_NAME
        cat .cppScript.tocreate | awk '{ print toupper ($0) }' >> $FILE_NAME
        echo >> $FILE_NAME

        while true; do
            whiptail --cancel-button "Next" --inputbox "Name headers you want to include one by one" $DIALOG_H $DIALOG_W "<>" 2>.cppScript.input

            if [ $? = 0 ]; then
                echo "# include $(cat .cppScript.input)" >> $FILE_NAME
            else
                break
            fi
        done

        # NOTE: Possibility of typing the name of a cpp file that i parse to get the function prototypes

        printf "\n#endif\n" >> $FILE_NAME

        whiptail --yesno "Are you satisfied with the created file?" \
            $DIALOG_H $DIALOG_W $MENU_LIST_H
        if [ $? = 0 ]; then
            echo $FILE_NAME >> .cppScript.created
        else
            rm -rf $FILE_NAME
            hpp_create
        fi
    fi
}

class_create() {
    whiptail --inputbox "Give a name to the new Class.\n \
        \n- Any name would preferably be in CamelCase \
        \n- ClassName will also be the name of both cpp and hpp files \
        \n- Canonical form will be used untill script update" \
        $DIALOG_H $DIALOG_W "MyBestExemple" 2>.cppScript.tocreate

    if [ $(cat .cppScript.tocreate) ]; then
        CLASS_NAME=$(cat .cppScript.tocreate)

        if ls | grep -qx "$CLASS_NAME.cpp"; then
            whiptail --yesno "The file named $CLASS_NAME.cpp currently exists and would get overwritten\
                \n\nAre you sure?" $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                mv "$CLASS_NAME.cpp" "$BACKUP_D/$CLASS_NAME"
                true
            else
                return
            fi
        elif ls | grep -qx "$CLASS_NAME.hpp"; then
            whiptail --yesno "The file named $CLASS_NAME.hpp currently exists and would get overwritten\
                \n\nAre you sure?" $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                mv "$CLASS_NAME.hpp" "$BACKUP_D/$CLASS_NAME"
                true
            else
                return
            fi
        else
            whiptail --yesno "Do you confirm the class name $CLASS_NAME?" \
                $DIALOG_H $DIALOG_W $MENU_LIST_H

            if [ $? = 0 ]; then
                true
            else
                class_create
            fi
        fi

        touch $FILE_NAME

        sed -iE "s/\./_/g" .cppScript.tocreate
        echo -n "#ifndef " > $FILE_NAME
        cat .cppScript.tocreate | awk '{ print toupper ($0) }' >> $FILE_NAME
        echo -n "# define " >> $FILE_NAME
        cat .cppScript.tocreate | awk '{ print toupper ($0) }' >> $FILE_NAME
        echo >> $FILE_NAME

        while true; do
            whiptail --cancel-button "Next" --inputbox "Name headers you want to include one by one" $DIALOG_H $DIALOG_W "<>" 2>.cppScript.input

            if [ $? = 0 ]; then
                echo "# include $(cat .cppScript.input)" >> $FILE_NAME
            else
                break
            fi
        done

        # NOTE: Possibility of typing the name of a cpp file that i parse to get the function prototypes

        printf "\n#endif\n" >> $FILE_NAME

        whiptail --yesno "Are you satisfied with the created file?" \
            $DIALOG_H $DIALOG_W $MENU_LIST_H
        if [ $? = 0 ]; then
            echo $FILE_NAME >> .cppScript.created
        else
            rm -rf $FILE_NAME
            hpp_create
        fi
    fi
}

main() {

    while true
    do
        mkdir -p $BACKUP_D

        main_menu

        if grep -q "Exit" .cppScript.input; then
            clean_exit
        elif grep -q "Cpp" .cppScript.input; then
            cpp_create || continue
        elif grep -q "Hpp" .cppScript.input; then
            hpp_create || continue
        elif grep -q "Class" .cppScript.input; then
            class_create || continue
        elif grep -q "Cancel" .cppScript.input; then
            backup_exit
        # elif grep -q "Back" .cppScript.input; then
        #     main_menu
        else
            clean_exit
        fi
    done

    exit
}

main
