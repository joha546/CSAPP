
blah:blah.o 
	cc blah.o -o blah  # Runs third

blah.o : blah.c
	cc -c blah.c -o blah.o  # Runs second

blah.c:
	echo "Runs first"
	echo "int main() { return 0; }" > blah.c  
clean:
		rm -rf *-o blah