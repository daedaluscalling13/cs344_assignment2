movies: process_file.o process.o prompt.o process_prompt.o invalid_prompt.o movies.o
	gcc --std=gnu99 -o movies_by_year process_file.o process.o prompt.o process_prompt.o invalid_prompt.o movies.o

movies.o: movies.c movie.h
	gcc --std=gnu99 -c -g movies.c

process_file.o: process_file.h process_file.c movie.h
	gcc --std=gnu99 -c -g process_file.h process_file.c

prompt.o: prompt.h prompt.c
	gcc --std=gnu99 -c -g prompt.h prompt.c

invalid_prompt.o: invalid_prompt.h invalid_prompt.c
	gcc --std=gnu99 -c -g invalid_prompt.h invalid_prompt.c

process.o: process.h process.c process_prompt.o
	gcc --std=gnu99 -c -g process.h process.c process_prompt.o

process_prompt.o: process_prompt.h process_prompt.c
	gcc --std=gnu99 -c -g process_prompt.h process_prompt.c