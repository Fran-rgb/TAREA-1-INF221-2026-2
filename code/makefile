all:
	$(MAKE) -C sorting
	$(MAKE) -C matrix_multiplication

run-sorting:
	$(MAKE) -C sorting run

run-matrix:
	$(MAKE) -C matrix_multiplication run

run-all: run-sorting run-matrix

clean:
	$(MAKE) -C sorting clean
	$(MAKE) -C matrix_multiplication clean

.PHONY: all run-sorting run-matrix run-all clean