#!/usr/bin/bash

declare -a Allowed_Extensions=("txt" "pdf" "jpg")

Directory_Path=$1

declare extension=""

declare -a Dir_Contents=$(ls -ap ${1} | grep -v /)

echo "${Dir_Contents}">Files_Names.txt #"${myarray[@]}"




#Corner cases:
#Files-Starting_with_. , Files with no Extension


function Make_Dir(){
    #If allowed Extension
    if ( Is_Extension_Allowed "$1" == 1 ); then
        #Check if Directory Exists or not
        if test -d "${Directory_Path}/$1"; then
            #echo "Directory exists."
            echo "Dir already exists"
        else
            #echo "Directory Does NOT exist."
            mkdir "${Directory_Path}/$1"
            
        fi
        extension="$1"
    #else if not allowed extension
    else
        extension="Misc"
        #Check if Misc Directory Exists or not
        if test -d "${Directory_Path}/Misc"; then
            #echo "Directory exists."
            echo "Misc Dir already exists"
        else
            #echo "Misc Directory Does NOT exist."
            mkdir "${Directory_Path}/Misc"
        fi
        
    fi

}

function Is_Extension_Allowed(){
    #check if extension is allowed or not
    for i in "${Allowed_Extensions[@]}"; do
        if [[ "${Allowed_Extensions[i]}" == "${1}" ]]; then
            #echo "The two strings are the same"
            echo 1;
            return 1;
        else
            echo 0;
            return 0;
        fi

    done

}


function Get_Extension(){
    #Extract Extension
    extension=${1##*.}
    Make_Dir "$extension"
}

function Move_File(){

    mv "${Directory_Path}/$1" "${Directory_Path}/${extension}/"
}


function main(){
    #Logic
    #1. Get Dir from argument
    #2. Extract names in Dir
    #3. loop on files and do operations on each file
    while IFS= read -r line; do
        #echo "Text read from file: $line"
        Get_Extension "$line"
        #Move this file to its specific Dir
        Move_File "$line"
    done < Files_Names.txt

    # at the end delete Files_Names.txt
    #rm Files_Names.txt
}


#call main
main
