#include <fcgi_stdio.h>

int main(void) {
    while (FCGI_Accept() >= 0) {
        printf("Content-Type: text/html\r\n\r\n");
        printf("<html>");
        printf("<head><title>Simple FastCGI Server</title></head>");
        printf("<body><h1>Hello, World!</h1></body>");
        printf("</html>");
    }

    return 0;
}
