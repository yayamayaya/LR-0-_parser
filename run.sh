#!/bin/bash

valgrind -s --leak-check=full --show-leak-kinds=all build/init_test