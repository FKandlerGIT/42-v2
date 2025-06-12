Functions that might help, throughout the 'printf' project.

ft_strlen (for calculating length when printing strings.)
ft_strdup (if you need to duplicate strings (e.g. precision handling).)
ft_strchr  (for checking format specifiers (e.g. %, d, s, etc.).)
ft_substr  (if you extract parts of strings.)
ft_strjoin  (building formatted strings step-by-step.)
ft_itoa  (converting integers to strings for %d, %i, etc.)
ft_isdigit(for parsing width/precision.)
ft_itoa(again, crucial for printing integers.)
ft_putchar_fd(), ft_putstr_fd(helpful for writing characters/strings to stdout)
(though you may want to write your own versions that count printed characters).
ft_memset(e.g., for zero-initializing buffers.)
ft_bzero(same as above.)
ft_calloc(safer dynamic allocation, especially if you build intermediate buffers.)
ft_strlcpy, ft_strlcat(for safe string building if needed.)
ft_strncmp(if you ever want to check format sequences.)