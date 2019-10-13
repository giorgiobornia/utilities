#!/bin/bash


grep -rl old_string * | xargs  sed -i "" "s/old_string/new_string/g" #on a Mac you need "" after -i
