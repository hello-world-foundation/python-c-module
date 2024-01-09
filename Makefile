build:
	$(CC) -lpython3.11 -shared -fPIC `pkg-config --cflags --libs python-3.11` $(wildcard *.c) -o hello.so

clean:
	rm -f *.so

test: build
	python -c "\
	import hello ;\
	num=hello.hello() ;\
	print(\"return=%d\" % num) ;"
