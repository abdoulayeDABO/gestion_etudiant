# Compilateur
CC = gcc

# Drapeaux du compilateur
# CFLAGS = -Wall

# Exécutable cible
TARGET = programme.exe

# Fichiers source
SOURCES = main.c etudiants.c

# Fichiers objets
OBJECTS = $(SOURCES:.c=.o)

# Construire l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compiler les fichiers source en fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers générés
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
