LD_FLAGS += -L$(DIR) -Wl,-R$(DIR) '-Wl/home/joey/Documents/CSI-345/steamSearch'
CXX = g++


main: main.cpp libsteamSearch.so libJSONParser.so
	$(CXX) $(CFLAGS) -o main main.cpp -ggdb -ldl -L/home/joey/Documents/CSI-345/steamSearch -lsteamSearch -L/home/joey/Documents/CSI-345/steamSearch/linux64 -lsteam_api -L/home/joey/Documents/CSI-345/steamSearch/cpr/lib -lcpr -lcurl -lcurlpp -L/home/joey/Documents/CSI-345/steamSearch/cpr/lib -lcurl-d -L/home/joey/Documents/CSI-345/steamSearch -lJSONParser

steamSearch.o: steamSearch.cpp
	$(CXX) -c steamSearch.cpp -o steamSearch.o -fPIC -ggdb

libsteamSearch.so: steamSearch.o
	$(CXX) -shared  -Wl,-soname,libsteamSearch.so -o libsteamSearch.so steamSearch.o -fPIC -ggdb

JSONParser.o: JSONParser.cpp
	$(CXX) -ggdb -c JSONParser.cpp -o JSONParser.o -fPIC

libJSONParser.so: JSONParser.o
	$(CXX) -ggdb -shared -Wl,-soname,libJSONParser.so -o libJSONParser.so JSONParser.o -fPIC

clean:
	rm -rf *.o *.so main steamSearch