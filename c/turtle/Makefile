all:		turtle test clean

turtle:		turtle.c

clean:
	rm -f turtle

test:		turtle
	@echo RUN turtle tests
	@./turtle < turtle_tests > turtle_results 2>&1
	@diff turtle_results turtle_expects || (echo "turtle test FAILED"; exit 1)
	@rm -rf turtle_results
