format:
	set -f
	find ./noise-network/ \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} \;
	find ./noise-network/ \( -name '*.cmake' -o -name 'CMakeLists.txt' \) -exec cmake-format -i {} \;
	set +f
