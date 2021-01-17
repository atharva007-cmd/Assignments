CXX = g++
CXXFLAGS = -Wall -g -Os -fstack-usage -Os -ffunction-sections -fdata-sections

all:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp fuzzy.cpp -o fuzzy
	@ echo "📜🏃 Running ...\n"
	@ ./fuzzy

compile:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp fuzzy.cpp -o fuzzy

run:
	@ echo "📜🏃 Running ...\n"
	@ ./fuzzy

run-debug:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp fuzzy.cpp -o fuzzy
	@ echo "📜🏃 Running ...\n"
	@ ./fuzzy
	@ echo "💾 Memory used:\b"
	@ cat *.su

clean:
	@ echo "🧹 Cleaning up..."
	@ rm -rf *.out
	@ rm -rf *.exe
	@ rm -rf *.su
	@ rm -rf fuzzy