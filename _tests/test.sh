#!/bin/bash

make -C .. &&
	cc test.c -I ../incs -L .. -lft -o og -fsanitize=address &&
	cc test.c -I ../incs -L .. -lft -o ft -DFT -fsanitize=address &&
	diff <(./og $@) <(./ft $@) --side-by-side --color=always
