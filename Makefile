compile:
	cmake -B build -S .
	$(MAKE) -C build

run:
	./build/src/lvc

clean:
	rm -rf build
