#define EU_MODE 0
#define US_MODE 1

void set_mode(int mode, int *rec_mode);
void get_info(int mode);
void show_info(int mode, int distance, double fuel);