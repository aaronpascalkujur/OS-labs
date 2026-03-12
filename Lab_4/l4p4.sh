#!/bin/bash

get_user_info() {
    echo "User     Login Time"
    echo "-------------------"
    who | awk '{print $1, $3, $4}'
}

get_user_info