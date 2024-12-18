#include "so_long.h" // oder ein entsprechendes Headerfile
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	int fd = open("map.ber", O_RDONLY); // Öffne die Testdatei
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Reading lines from map.ber:\n");
	while ((line = get_next_line(fd))) // Lese Zeilen mit get_next_line
	{
		printf("Line: %s\n", line); // Gib die Zeile aus
		free(line);                 // Gebe den Speicher für die Zeile frei
	}
	close(fd); // Schließe die Datei
	return (0);
}
