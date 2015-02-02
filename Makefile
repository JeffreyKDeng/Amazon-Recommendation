MKFILE    = Makefile

GCC       = gcc -g -O0 -Wall -Wextra -std=gnu99

CHEADER   = bookCountList.h bookListList.h
CSOURCE   = amazon.c ${CHEADER:.h=.c}
CSOURCE2  = amazonDriver.c ${CHEADER:.h=.c}

OBJECTS   = ${CSOURCE:.c=.o}
OBJECTS2  = ${CSOURCE:.c=.o}

EXECBIN   = amazon
EXECBIN2	 = amazonDriver

SOURCES   = ${CHEADER} ${CSOURCE} 
SOURCES2  = ${CHEADER} ${CSOURCE2} 
all : ${EXECBIN} ${EXECBIN2}
			
${EXECBIN} : ${OBJECTS}
	${GCC} -o $@ ${OBJECTS}
${EXECBIN2} : ${OBJECTS2}
	${GCC} -o $@ ${OBJECTS2}

%.o : %.c
	${GCC} -c $<



ifeq "${NEEDINCL}" ""
endif
