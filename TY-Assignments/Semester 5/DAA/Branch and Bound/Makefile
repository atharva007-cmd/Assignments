
CXX = g++
CXXFLAGS = -g -Os -fstack-usage -Os -ffunction-sections -fdata-sections

all:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp travelling-salesperson.cpp -o travelling-salesperson
	@ echo "📜🏃 Running ...\n"
	@ ./travelling-salesperson

compile:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp travelling-salesperson.cpp -o travelling-salesperson

run:
	@ echo "📜🏃 Running ...\n"
	@ ./travelling-salesperson

run-debug:
	@ echo "🛠️ Building ..."
	@ $(CXX) $(CXXFLAGS) main.cpp travelling-salesperson.cpp -o travelling-salesperson
	@ echo "📜🏃 Running ...\n"
	@ ./travelling-salesperson
	@ echo "💾 Memory used:\b"
	@ cat *.su

clean:
	@ echo "🧹 Cleaning up..."
	@ rm -rf *.out
	@ rm -rf *.exe
	@ rm -rf *.su
	@ rm -rf travelling-salesperson