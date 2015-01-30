JAVAC=javac
sources = $(wildcard *.java)
classes = $(sources:.java=.class)

all: $(classes)

run:
	java decompose
clean :
	rm -f *.class

%.class : %.java
	$(JAVAC) $<

