cc test.c -I ../incs -L .. -lft -o og
cc test.c -I ../incs -L .. -lft -o ft -DFT

echo $@
diff <(./og $@) <(./ft $@) --side-by-side --color=always
