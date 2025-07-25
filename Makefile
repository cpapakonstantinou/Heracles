TARGET ?= 12labors
CXX = g++-13
CXXFLAGS = -std=c++23 -Wall -O0 -I ./inc -march=native
LDFLAGS ?=
LDLIBS ?= 
HEADERS = inc/oracle.h inc/heracles.h inc/pythia.h
PREFIX ?= /usr
INSTALLDIR ?= $(PREFIX)/include/oracle

$(TARGET).o:test/$(TARGET).cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(TARGET):$(TARGET).o
	${CXX} -o $(TARGET) $^ ${LDFLAGS} ${LDLIBS}

clean:
	$(RM) *.o $(TARGET).ii $(TARGET).s

cleanall: clean
	$(RM) $(TARGET)

install: $(HEADERS)
	install -d $(INSTALLDIR)
	install -m 644 $(HEADERS) $(INSTALLDIR)

uninstall:
	$(RM) -r $(INSTALLDIR)

.DEFAULT_GOAL=install