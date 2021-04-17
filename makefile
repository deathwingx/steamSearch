LD_FLAGS += -L$(DIR) -Wl,-R$(DIR) '-Wl/home/joey/Documents/CSI-345/steamSearch'
CXX = g++


main: main.cc libtest.so
	$(CXX) $(CFLAGS) -o main main.cc -ldl -L/home/joey/Documents/CSI-345/steamSearch -ltest

test.o: test.cc
	$(CXX) -c test.cc -o test.o -fPIC

libtest.so: test.o
	$(CXX) -shared  -Wl,-soname,libtest.so -o libtest.so test.o -fPIC

clean:
	rm -rf *.o *.so