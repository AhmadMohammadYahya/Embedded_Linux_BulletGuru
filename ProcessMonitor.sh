#!/usr/bin/bash -i

source process_monitor.conf



#Verbs
#view[list], Manage, Analyze


#req.
    #Real time monitoring
    # Search and filter
    # Interactive mode
    # Resource usage alert
    # Logging
    # Configuration option

function ListProcesses(){
    clear
    echo "Real-Time Process List (updates every $UPDATE_INTERVAL seconds)"
    ps -eo pid,user,%cpu,%mem,start,time,comm --sort=-%cpu | head -n 20

}

function Get_Detailed_Process_Info_By_ID(){
    read -rp "Enter Process ID: " PID
    ps -fp "$PID"
    
}

function Get_Detailed_Process_Info_By_Name(){
    read -rp "Enter Process Name: " PID_Name
    pidof "$PID_Name"
    ps -fp "$PID"
}

function Kill_Process_By_ID(){
    read -rp "Enter Process ID: " PID
    kill -9 "$PID"
    
}

function Kill_Process_By_Name(){
    read -rp "Enter Process Name: " PID_Name
    pidof "$PID_Name"
    kill -9 "$PID"
}


function main(){

    while true
    do
        ListProcesses
        echo "Welcome to Process Monitor Script, Which option do you want?"
        echo "1. Get detailed Info about specific process"
        echo "2. Kill a specific process"
        echo "3. Display overall system process statistics"
        
        read -rt $UPDATE_INTERVAL -p "Enter option number: " choice  # Wait for input for $UPDATE_INTERVAL seconds
        
        case "$choice" in

        1)  Get_Detailed_Process_Info_By_ID
            ;;
        2)  Kill_Process_By_ID
            ;;
        3)  Display_Statistics
            ;;
        *)
        ;;
        esac
    done



}

main
