for file in test/**/test.sh; do
	echo "Testing" $(dirname $file | cut -d'/' -f2)
	(cd $(dirname $file) && bash ./test.sh)
done
