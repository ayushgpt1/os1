#!/bin/bash

# Display top 10 processes by CPU usage
echo "Top 10 processes by CPU usage:"
ps -eo pid,%cpu,%mem,cmd --sort=-%cpu | head -n 11
