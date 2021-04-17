LD_FLAGS += -L$(DIR) -Wl,-R$(DIR) '-Wl/home/joey/Documents/CSI-345/steamSearch'
CXX = g++


main: main.cpp libsteamSearch.so
	$(CXX) $(CFLAGS) -o main main.cpp -ldl -L/home/joey/Documents/CSI-345/steamSearch -lsteamSearch -L/home/joey/Documents/CSI-345/steamSearch/linux64 -lsteam_api

steamSearch.o: steamSearch.cpp
	$(CXX) -c steamSearch.cpp -o steamSearch.o -fPIC

libsteamSearch.so: steamSearch.o
	$(CXX) -shared  -Wl,-soname,libsteamSearch.so -o libsteamSearch.so steamSearch.o -fPIC

clean:
	rm -rf *.o *.so