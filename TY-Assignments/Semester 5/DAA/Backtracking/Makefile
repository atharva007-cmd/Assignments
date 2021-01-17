
CXX = g++
CXXFLAGS = -Wall -g -Os -fstack-usage -Os -ffunction-sections -fdata-sections

all:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp n-queen.cpp -o n-queen
	@ echo "📜🏃 Running ...\n"
	@ ./n-queen 4

compile:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp n-queen.cpp -o n-queen

run:
	@ echo "📜🏃 Running ...\n"
	@ ./n-queen 4

run-debug:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp n-queen.cpp -o n-queen
	@ echo "📜🏃 Running ...\n"
	@ ./n-queen 4
	@ echo "💾 Memory used:\b"
	@ cat *.su

clean:
	@ echo "🧹 Cleaning up..."
	@ rm -rf *.out
	@ rm -rf *.exe
	@ rm -rf *.su
	@ rm -rf n-queen